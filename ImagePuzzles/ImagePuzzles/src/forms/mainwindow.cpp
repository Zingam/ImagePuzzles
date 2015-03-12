#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QtCore/QDebug>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QMessageBox>

#include "../forms/dialogabout.h"

#include "../application/constants.h"
#include "../core/puzzle.h"
#include "../core/puzzleloader.h"


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    applicationInfo(res_applicationTitle, res_authorName),
    pixmap_ImageLogo(res_fileName_ImageLogo)
{
    ui->setupUi(this);

    // Set the icons manually due to a shortcomming in Qbs
    ui->action_About->setIcon(QIcon(":/icons/About"));
    ui->action_Exit->setIcon(QIcon(":/icons/Exit"));
    ui->action_Reload->setIcon(QIcon(":/icons/Reload"));
    ui->action_Run->setIcon(QIcon(":/icons/Run"));
    ui->action_SaveAs->setIcon(QIcon(":/icons/Save As"));

    ui->pushButton_Puzzles_Reload->setIcon(QIcon(":/icons/Reload"));
    ui->pushButton_Puzzles_Run->setIcon(QIcon(":/icons/Run"));

    this->setWindowTitle(tr(this->applicationInfo.title));
    this->setWindowIcon(QIcon(":/icons/Icon"));

    this->connect(
                ui->pushButton_Puzzles_Run, &QPushButton::clicked,
                this, &MainWindow::on_action_Run_triggered);
    this->connect(
                ui->pushButton_Puzzles_Reload, &QPushButton::clicked,
                this, &MainWindow::on_action_Reload_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* ***************************************************************************
 * PRIVATE: METHODS
 * ***************************************************************************/
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


/* ***************************************************************************
 * PRIVATE: SLOTS
 * ***************************************************************************/
///
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
    qDebug() << "Reload";
}

void MainWindow::on_action_Run_triggered()
{
    this->puzzles = loadPuzzles();

    for (Puzzle* puzzle: this->puzzles)
    {
        if (puzzle->isLoaded)
        {
            QString itemName =
                    puzzle->puzzleInfo->number
                    + QString(" - ")
                    + puzzle->puzzleInfo->name;

            this->ui->comboBox_Puzzles->addItem(itemName);

            const char* const path = "Puzzles/Puzzle001";
            puzzle->run(path);
        }
    }
}

void MainWindow::on_action_SaveAs_triggered()
{
    qDebug() << "Save As";
}
