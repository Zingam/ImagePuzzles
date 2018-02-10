#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "../application/applicationinfo.hpp"

#include <QtCore/QList>
#include <QtWidgets/QMainWindow>

#include <string>
#include <vector>

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
    void actionNotImplemented();
    void closeEvent(QCloseEvent* event);
    void setPuzzle(Puzzle* puzzle);

private slots:
    void on_action_About_triggered();
    void on_action_Exit_triggered();
    void on_action_Load_Default_Image_triggered();
    void on_action_Load_Image_triggered();
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
