#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) // liczba arg wywolania i tablica wskaznikow do tych arg
{
    QApplication a(argc, argv); // instancja Qapp - kotekst naszej app
    MainWindow w; // na stosie tworzymy okno
    w.show(); // pokaz

    return a.exec(); // a.exex -> QApp otworzylo kolejke i nasluchuje na kolejne reakcje - a.exec uruchamia nieskonczona petle
}
