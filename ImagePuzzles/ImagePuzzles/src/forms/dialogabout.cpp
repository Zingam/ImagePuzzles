#include "dialogabout.h"
#include "ui_dialogabout.h"

#include <QtGui/QFontMetrics>


#include "../application/constants.h"

Dialog_About::Dialog_About(
        const ApplicationInfo& applicationInfo,
        const QPixmap& pixmap_Icon,
        QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog_About)
{
    // Remove ? from TitleBar
    Qt::WindowFlags windowFlags = this->windowFlags();
    windowFlags &= ~Qt::WindowContextHelpButtonHint;

    this->setWindowFlags(windowFlags);

    // Setup the UI
    ui->setupUi(this);

    this->setWindowTitle(applicationInfo.title);

    if (!pixmap_Icon.isNull()) {
        // Set the icon for the dialog
        this->setWindowIcon(QIcon(":/icons/Icon"));

        // Set the logo image
        ui->label_ImageLogo->setMinimumSize(pixmap_Icon.size());
        ui->label_ImageLogo->setPixmap(pixmap_Icon);
    }
    else {
        QString text(QString(tr("ERROR: No valid image")));
        QFontMetrics fontMetrics(ui->label_ImageLogo->font());
        ui->label_ImageLogo->setMinimumSize(fontMetrics.size(Qt::TextSingleLine, text));
        ui->label_ImageLogo->setText(text);
    }

    // The the about text
    QString text(res_dialog_About_Text);
    ui->label_Text->setText(text
                            .arg(applicationInfo.title)
                            .arg(applicationInfo.author));
}

Dialog_About::~Dialog_About()
{
    delete ui;
}

void Dialog_About::on_pushButton_Exit_clicked()
{
    /* If the About dialog returns QDialog::DialogCode::Rejected
     * then the application should ask the user to quit.
     * This action should be handled in the parent that created
     * this dialog.
     * */
    this->reject();
}
