#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../common/applicationinfo.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent* event);

private slots:
    void on_action_About_triggered();
    void on_action_Exit_triggered();
    void on_action_Reload_triggered();
    void on_action_Run_triggered();
    void on_action_SaveAs_triggered();

private:
    Ui::MainWindow* ui;

    ApplicationInfo applicationInfo;
    QPixmap pixmap_ImageLogo;
};

#endif // MAINWINDOW_H
