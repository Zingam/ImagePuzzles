#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QList>
#include <QtWidgets/QMainWindow>


#include "../application/applicationinfo.h"

namespace Ui {
class MainWindow;
}

class Puzzle;


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

    QList<Puzzle*> puzzles;
};

#endif // MAINWINDOW_H
