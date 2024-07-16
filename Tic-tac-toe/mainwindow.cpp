#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->StartBtn,SIGNAL(clicked()),this,SLOT(OnStartButtonClicked()));
    connect(ui->QuitBtn,SIGNAL(clicked()),this,SLOT(OnStartButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnStartButtonClicked()
{
   QString name1 = ui->Player1_name->text();
   QString name2 = ui->Player2_name->text();
       secondwindow *sw = new secondwindow(this, name1, name2);

       sw->exec();
       hide();
}

void MainWindow::OnQuitButtonClicked()
{
    QApplication::quit();
}
