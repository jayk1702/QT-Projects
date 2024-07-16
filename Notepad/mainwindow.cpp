#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(OnActionNewClicked()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(OnActionOpenClicked()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(OnActionSaveClicked()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(OnActionExitClicked()));
    connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(OnActionCopyClicked()));
    connect(ui->actionCut,SIGNAL(triggered()),this,SLOT(OnActionCutClicked()));
    connect(ui->actionPaste,SIGNAL(triggered()),this,SLOT(OnActionPasteClicked()));
    connect(ui->actionUndo,SIGNAL(triggered()),this,SLOT(OnActionUndoClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnActionNewClicked()
{
    currentFile.clear();

    ui->textBox->setText(QString());
}

void MainWindow::OnActionOpenClicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open file");
    QFile file(filename);
    currentFile = filename;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning", "Can't open file: ");
        return;
    }
    setWindowTitle(filename);

    QTextStream in(&file);

    QString text = in.readAll();

    ui->textBox->setText((text));

    file.close();

}

void MainWindow:: OnActionSaveClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Can't save file: ");
            return;
        }
        currentFile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->textBox->toPlainText();
        out << text;
        file.close();

}


void MainWindow:: OnActionExitClicked()
{
    QApplication::quit();
}

void MainWindow:: OnActionCopyClicked()
{
    ui->textBox->copy();
}

void MainWindow:: OnActionCutClicked()
{
    ui->textBox->cut();
}

void MainWindow:: OnActionPasteClicked()
{
    ui->textBox->paste();
}

void MainWindow:: OnActionUndoClicked()
{
    ui->textBox->undo();
}
