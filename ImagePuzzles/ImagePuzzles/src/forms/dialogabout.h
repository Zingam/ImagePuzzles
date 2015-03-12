#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>

#include "../application/applicationinfo.h"

namespace Ui {
class Dialog_About;
}


class Dialog_About : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_About(
            const ApplicationInfo& applicationInfo,
            const QPixmap& pixmap_Icon,
            QWidget* parent = 0);
    ~Dialog_About();

private slots:
    void on_pushButton_Exit_clicked();

private:
    Ui::Dialog_About *ui;
};

#endif // DIALOGABOUT_H
