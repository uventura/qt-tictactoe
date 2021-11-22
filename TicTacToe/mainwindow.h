#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGridLayout>
#include <QList>
#include <QMessageBox>

#include "clickfield.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getPressedButton();

private:
    Ui::MainWindow *ui;

    ClickField* areas[9];
    QString currentPlayer;

    int playedPositions;

    void restartGame();
    void endGame(QString Message);
    bool someoneWon();
};
#endif // MAINWINDOW_H
