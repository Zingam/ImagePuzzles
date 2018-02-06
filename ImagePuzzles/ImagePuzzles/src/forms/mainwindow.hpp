#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <string>
#include <vector>

#include <QtCore/QList>
#include <QtWidgets/QMainWindow>

#include "../application/applicationinfo.hpp"


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
    void setPuzzle(Puzzle* puzzle);

private slots:
    void on_action_About_triggered();
    void on_action_Exit_triggered();
    void on_action_Reload_triggered();
    void on_action_Run_triggered();
    void on_action_SaveAs_triggered();

    void on_comboBox_Puzzles_activated(int index);

private:
    Ui::MainWindow* ui;

    ApplicationInfo applicationInfo;
    QPixmap pixmap_ImageLogo;
    QPixmap pixmap_PuzzleResult;

    QList<Puzzle*> puzzles;

    std::vector<std::string> parameters;
};

#endif // MAINWINDOW_HPP
