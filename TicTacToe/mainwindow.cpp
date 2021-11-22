#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:black;");

    playedPositions = 0;
    currentPlayer = "X";

    areas[0] = ui->pushButton_1;
    areas[1] = ui->pushButton_2;
    areas[2] = ui->pushButton_3;
    areas[3] = ui->pushButton_4;
    areas[4] = ui->pushButton_5;
    areas[5] = ui->pushButton_6;
    areas[6] = ui->pushButton_7;
    areas[7] = ui->pushButton_8;
    areas[8] = ui->pushButton_9;

    for(int i=0;i<9;++i)
    {
        areas[i]->setTextField("*");
        areas[i]->setChangedValue(&currentPlayer);
        areas[i]->setIndex(i);

        connect(areas[i], &ClickField::pressedButtonField, this, &MainWindow::getPressedButton);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::restartGame()
{
    currentPlayer = "X";
    playedPositions = 0;

    this->setStyleSheet("background-color:white;");

    for(int i=0;i<9;++i)
        areas[i]->setTextField("*");
}

bool MainWindow::someoneWon()
{
    // Lines and Columns
    for(int i=0;i<3;++i)
    {
        if(areas[i*3]->getValue()!="*"
        && areas[i*3]->getValue()==areas[1+i*3]->getValue()
        && areas[i*3]->getValue() == areas[2+i*3]->getValue())
            return true;
        if(areas[i]->getValue()!="*"
        && areas[i]->getValue()==areas[i+3]->getValue()
        && areas[i]->getValue() == areas[i+6]->getValue())
            return true;
    }

    // Diagonals
    if(areas[0]->getValue()!="*"
    && areas[0]->getValue()==areas[4]->getValue()
    && areas[0]->getValue() == areas[8]->getValue())
        return true;
    if(areas[2]->getValue()!="*"
    && areas[2]->getValue()==areas[4]->getValue()
    && areas[2]->getValue() == areas[6]->getValue())
        return true;

    return false;
}

void MainWindow::endGame(QString Message)
{
    this->setStyleSheet("background-color:white;");

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Game Over", Message+"\nQuit?",
            QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else
        restartGame();
}

void MainWindow::getPressedButton()
{
    playedPositions+=1;

    if(someoneWon())
    {
        QString Winner = (currentPlayer == "X" ? "O" : "X");
        endGame("Player '"+Winner+"' Won!!");
        return;
    }

    if(playedPositions == 9)
    {
        endGame("Draw!!");
        return;
    }
}
