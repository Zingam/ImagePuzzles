#ifndef DIALOGABOUT_HPP
#define DIALOGABOUT_HPP

#include <QDialog>

#include "../application/applicationinfo.hpp"

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

#endif // DIALOGABOUT_HPP
