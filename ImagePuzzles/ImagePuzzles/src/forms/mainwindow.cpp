#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "../forms/dialogabout.hpp"

#include "../application/constants.hpp"
#include "../core/puzzle.hpp"
#include "../core/puzzleloader.hpp"

#include <common/puzzlepixmap.hpp>

#include <QtCore/QDebug>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QMessageBox>

#include <iostream>
#include <map>
#include <vector>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    applicationInfo(res_applicationTitle, res_authorName),
    pixmap_ImageLogo(res_fileName_ImageLogo)
{
    ////////////////////////////////////////////////////////////////////////////
    // Setup UI
    ////////////////////////////////////////////////////////////////////////////
    ui->setupUi(this);

    // Set the MainWindow properties
    this->setWindowTitle(tr(this->applicationInfo.title));
    this->setWindowIcon(QIcon(":/icons/Icon"));

    // Set the icons for the QAction widgets due to a shortcomming in Qbs
    ui->action_About->setIcon(QIcon(":/icons/About"));
    ui->action_Exit->setIcon(QIcon(":/icons/Exit"));
    ui->action_Load_Default_Image->setIcon(QIcon(":/icons/Load Default Image"));
    ui->action_Load_Image->setIcon(QIcon(":/icons/Load Image"));
    ui->action_Reload->setIcon(QIcon(":/icons/Reload"));
    ui->action_Run->setIcon(QIcon(":/icons/Run"));
    ui->action_SaveAs->setIcon(QIcon(":/icons/Save As"));

    // Set the icons for the QPushButton widgets
    ui->pushButton_Puzzles_Reload->setIcon(QIcon(":/icons/Reload"));
    ui->pushButton_Puzzles_Run->setIcon(QIcon(":/icons/Run"));

    // Connect clicked() signals
    this->connect(
                ui->pushButton_Puzzles_Reload, &QPushButton::clicked,
                this, &MainWindow::on_action_Reload_triggered);
    this->connect(
                ui->pushButton_Puzzles_Run, &QPushButton::clicked,
                this, &MainWindow::on_action_Run_triggered);

    ////////////////////////////////////////////////////////////////////////////
    // Load the Puzzles
    ////////////////////////////////////////////////////////////////////////////
    this->puzzles = loadPuzzles();

    for (Puzzle* puzzle: this->puzzles)
    {
        if (puzzle->isLoaded)
            this->ui->comboBox_Puzzles->addItem(puzzle->puzzleTitle);
    }

    this->setPuzzle(this->puzzles[0]);
}

MainWindow::~MainWindow()
{
    delete ui;
}


////////////////////////////////////////////////////////////////////////////////
// PRIVATE: METHODS
////////////////////////////////////////////////////////////////////////////////
void MainWindow::actionNotImplemented()
{
    QMessageBox::warning(
                    this,
                    tr("Action Not Implemented"),
                    tr("This action is not implemented yet!"),
                    QMessageBox::Ok,
                    QMessageBox::NoButton);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Exit"));
    messageBox.setWindowIcon(QIcon(":/icons/Icon"));
    messageBox.setIcon(QMessageBox::Question);
    messageBox.setText(
                tr(res_MainWindow_action_Exit_QMessageBox_Text)
                .arg(this->applicationInfo.title));
    messageBox.setInformativeText(
                tr(res_MainWindow_action_Exit_QMessageBox_InformativeText)
                .arg(this->applicationInfo.title)
                .arg(this->applicationInfo.author));
    messageBox.setStandardButtons(QMessageBox::Yes |QMessageBox::Abort);

    QMessageBox::StandardButton standardButton =
            static_cast<QMessageBox::StandardButton>(messageBox.exec());
    if (QMessageBox::Yes == standardButton)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::setPuzzle(Puzzle* puzzle)
{
    if (nullptr != puzzle)
    {
        //ui->tab_label_SourceImage->hide();

        // Set Parameters line edit
        const char* const lparameters = puzzle->puzzleInfo->paramaters;
        if (nullptr != lparameters)
        {
            ui->lineEdit_Puzzles_Parameters->setText(lparameters);
        }

        // Set Implementations combobox
        ui->comboBox_Implementations->clear();
        const PuzzleInfo::Implementations* implementations
                = puzzle->puzzleInfo->implementations;

        for(PuzzleInfo::ImplementationType implementation: (*implementations))
        {
            switch(implementation)
            {
                case PuzzleInfo::CPlusPlus:
                {
                    ui->comboBox_Implementations->addItem(IMPLEMENTATION_TYPE_CPlusPlus);
                } break;
                case PuzzleInfo::OpenCL:
                {
                    ui->comboBox_Implementations->addItem(IMPLEMENTATION_TYPE_OpenCL);
                } break;
                case PuzzleInfo::OpenGL:
                {
                    ui->comboBox_Implementations->addItem(IMPLEMENTATION_TYPE_OpenGL);
                }
            }
        }

        // Set Image tab
        ui->tab_label_GeneratedImage->setText(tr("Click \"Run\" to execute the currently selected Puzzle"));
        if (puzzle->puzzleInfo->usesExternalImage)
        {
            ui->tab_frame_SourceImage->show();
        }
        else
        {
            ui->tab_frame_SourceImage->hide();
        }

        // Set Puzzle tab
        ui->tab_label_PuzzleText->setAlignment(Qt::AlignJustify | Qt::AlignTop);
        ui->tab_label_PuzzleText->setText(puzzle->puzzleInfo->text);
    }
    else
    {
        ui->lineEdit_Puzzles_Parameters->setText("");
        ui->tab_label_GeneratedImage->setText(tr("Please, select a Puzzle!"));
        ui->tab_label_PuzzleText->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tab_label_PuzzleText->setText("Valid Puzzle information is not available!");
    }
}

////////////////////////////////////////////////////////////////////////////////
// PRIVATE: SLOTS
////////////////////////////////////////////////////////////////////////////////

/// \brief MainWindow::on_action_About_triggered
/// Displays the About dialog in the Help menu. This slot gets automatically
/// connected to the action Ui::Ui_MainWindow::action_About.
///
void MainWindow::on_action_About_triggered()
{
    Dialog_About dialog_About(
                this->applicationInfo,
                this->pixmap_ImageLogo,
                this);

    // If pushButton_Exit was clicked, the About dialog will return a
    // QDialog::DialogCode::Rejected.
    QDialog::DialogCode dialogCode =
            static_cast<QDialog::DialogCode>(dialog_About.exec());
    if (QDialog::Rejected == dialogCode)
    {
        this->close();
    }
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_action_Reload_triggered()
{
    if (auto result = QMessageBox::question(
                this,
                tr("Reloading Puzzle"),
                tr("Continue reloading the Puzzle?"),
                QMessageBox::Yes,
                QMessageBox::No);
        QMessageBox::No == result)
    {
        return;
    }

    int selectedPuzzleIndex = ui->comboBox_Puzzles->currentIndex();
    if (0 > selectedPuzzleIndex)
    {
        return;
    }

    Puzzle* puzzle = this->puzzles[selectedPuzzleIndex];
    QString fullPathName = puzzle->fullPathName;
    QFileInfo file(fullPathName);

    qDebug() << "Reloading:         " << file.fileName();

    delete this->puzzles[selectedPuzzleIndex];
    this->puzzles[selectedPuzzleIndex] = nullptr;

    puzzle = loadPuzzle(file);
    if (nullptr != puzzle)
    {
        ui->comboBox_Puzzles->setItemText(selectedPuzzleIndex, puzzle->puzzleTitle);
        this->puzzles[selectedPuzzleIndex] = puzzle;
        this->setPuzzle(puzzle);
    }
    else
    {
        ui->comboBox_Puzzles->removeItem(selectedPuzzleIndex);
        puzzles.removeAt(selectedPuzzleIndex);
    }
}

void MainWindow::on_action_Load_Default_Image_triggered()
{
    qDebug() << "Load Default Image";

    actionNotImplemented();
}

void MainWindow::on_action_Load_Image_triggered()
{
    qDebug() << "Load Image";

    actionNotImplemented();
}

void MainWindow::on_action_Run_triggered()
{
    int selectedPuzzleIndex = ui->comboBox_Puzzles->currentIndex();
    if (0 > selectedPuzzleIndex)
    {
        return;
    }

    QString puzzleTitle = puzzles.at(selectedPuzzleIndex)->puzzleTitle;
    QString message = tr("Running: ") + puzzleTitle;

    ui->statusBar->showMessage(message);

    QString text = ui->lineEdit_Puzzles_Parameters->text();
    QStringList parametersList = text.split(" ", QString::SkipEmptyParts);
    parameters.clear();

    for (QString& parameter: parametersList)
    {
        parameters.push_back(parameter.toStdString());
    }

    void* parameters_VoidPtr = reinterpret_cast<void*>(&parameters);
    PuzzleInfo::ImplementationType implementationType = PuzzleInfo::CPlusPlus;

    QString implementationName = ui->comboBox_Implementations->currentText();


    if (implementationName == QString(IMPLEMENTATION_TYPE_CPlusPlus))
    {
        implementationType = PuzzleInfo::CPlusPlus;
    }
    else if (implementationName == QString(IMPLEMENTATION_TYPE_OpenCL))
    {
        implementationType = PuzzleInfo::OpenCL;
    }
    else if (implementationName == QString(IMPLEMENTATION_TYPE_OpenGL))
    {
        implementationType = PuzzleInfo::OpenGL;
    }

    PuzzlePixmap* puzzlePixmap =
            const_cast<Puzzle*>(puzzles.at(selectedPuzzleIndex))->run(parameters_VoidPtr, implementationType);

    PuzzleInfo::ErrorCodes errorCode = puzzles.at(selectedPuzzleIndex)->getErrorCode();
    switch(errorCode)
    {
        case PuzzleInfo::InvalidParameters:
        {
            QMessageBox::critical(
                        this,
                        tr("Invalid parameters"),
                        QString(res_MainWindow_action_Run_QMessageBox_InvalidParameters)
                        + tr("<p class='message'>You have entered invalid parameters.</p>"
                             "<p class='info'>Default values will be used instead.</p>"),
                        QMessageBox::Ok, QMessageBox::NoButton);

            break;
        }
        case PuzzleInfo::NoError:
        {
            break;
        }
    }

    if (nullptr != puzzlePixmap)
    {
        if ((nullptr != puzzlePixmap->buffer)
                && (0 < puzzlePixmap->size))
        {
            this->pixmap_PuzzleResult.loadFromData(
                        puzzlePixmap->buffer,
                        puzzlePixmap->size,
                        "PGM");
            if (!(this->pixmap_PuzzleResult.isNull()))
            {
                qDebug() << "Pixmap loaded";

                ui->tab_label_GeneratedImage->setPixmap(
                            this->pixmap_PuzzleResult.scaled(
                                ui->tab_label_GeneratedImage->geometry().size(),
                                Qt::AspectRatioMode::KeepAspectRatio));

                ui->tab_label_SourceImage->setPixmap(
                            this->pixmap_PuzzleResult.scaled(
                                ui->tab_label_GeneratedImage->geometry().size(),
                                Qt::AspectRatioMode::KeepAspectRatio));
            }
            else
            {
                qDebug() << "Pixmap failed to load";
            }
        }
    }
}

void MainWindow::on_action_SaveAs_triggered()
{
    qDebug() << "Save As";

    actionNotImplemented();
}

void MainWindow::on_comboBox_Puzzles_activated(int index)
{
    Puzzle* puzzle = this->puzzles[index];
    this->setPuzzle(puzzle);
}
