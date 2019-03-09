#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow // rozszerza Qmain
{
    Q_OBJECT //znacznik meta object complera srodowiskowego qt, wszystkie klasy z takim znaczikiem ma cos dla niego do zrobienia - np sloty

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots: //private slots - specjalne funkcje ktore spinaja zdarzenia z obsluga
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui; //wskaznik do mainWindow z przestrzeni nazw ui
};

#endif // MAINWINDOW_H
