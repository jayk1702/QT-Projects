#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

secondwindow::secondwindow(QWidget *parent,QString P1name, QString P2name) :
    QDialog(parent),
    ui(new Ui::secondwindow),player1Name(P1name),
    player2Name(P2name)

{
    ui->setupUi(this);

    ui->DisplayTurn->setText(player1Name);
    ui->DisplayTurn->setText(player2Name);

    connect(ui->Btn1,SIGNAL(clicked()),this,SLOT(OnBtn1Clicked()));
    connect(ui->Btn2,SIGNAL(clicked()),this,SLOT(OnBtn2Clicked()));
    connect(ui->Btn3,SIGNAL(clicked()),this,SLOT(OnBtn3Clicked()));
    connect(ui->Btn4,SIGNAL(clicked()),this,SLOT(OnBtn4Clicked()));
    connect(ui->Btn5,SIGNAL(clicked()),this,SLOT(OnBtn5Clicked()));
    connect(ui->Btn6,SIGNAL(clicked()),this,SLOT(OnBtn6Clicked()));
    connect(ui->Btn7,SIGNAL(clicked()),this,SLOT(OnBtn7Clicked()));
    connect(ui->Btn8,SIGNAL(clicked()),this,SLOT(OnBtn8Clicked()));
    connect(ui->Btn9,SIGNAL(clicked()),this,SLOT(OnBtn9Clicked()));

        if(count%2==1){
            ui->DisplayTurn->setText(player1Name + "'s turn");
        }else{
            ui->DisplayTurn->setText(player2Name + "'s turn");
        }
}


secondwindow::~secondwindow()
{
    delete ui;
}


void secondwindow::Check()
{
    if(count%2==1){
        ui->DisplayTurn->setText(player1Name + "'s turn");
    }else{
        ui->DisplayTurn->setText(player2Name + "'s turn");
    }
    QString Btn1=ui->Btn1->text();
    QString Btn2=ui->Btn2->text();
    QString Btn3=ui->Btn3->text();
    QString Btn4=ui->Btn4->text();
    QString Btn5=ui->Btn5->text();
    QString Btn6=ui->Btn6->text();
    QString Btn7=ui->Btn7->text();
    QString Btn8=ui->Btn8->text();
    QString Btn9=ui->Btn9->text();
    int flag=0;
    if(Btn1==Btn2 && Btn2==Btn3)
    {
        flag=1;
        if(Btn1=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn4==Btn5&& Btn5==Btn6)
    {
         flag=1;
        if(Btn4=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn7== Btn8&& Btn8==Btn9)
    {
         flag=1;
        if(Btn7=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn1==Btn4&& Btn4==Btn7)
    {
         flag=1;
        if(Btn1=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn2==Btn5&&Btn5==Btn8)
    {
         flag=1;
        if(Btn2=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn3==Btn6&&Btn6==Btn9)
    {
         flag=1;
        if(Btn3=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn1==Btn5&&Btn5==Btn9)
    {
         flag=1;
        if(Btn1=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(Btn3==Btn5&&Btn5==Btn7)
    {
         flag=1;
        if(Btn3=="X")
            QMessageBox::information(this,"RESULT",player1Name + " Wins");
        else
            QMessageBox::information(this,"RESULT",player2Name + " Wins");
    }
    else if(count==10)
    {
         flag=1;
        QMessageBox::information(this,"RESULT","DRAWN");
    }
    if(flag)
    {
        this->hide();
        MainWindow *w= new MainWindow();
        w->show();
    }
}

void secondwindow::OnBtn1Clicked()
{
    if(ui->Btn1->text()=="X" ||ui->Btn1->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn1->setText("X");
    }else{
        ui->Btn1->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn2Clicked()
{
    if(ui->Btn2->text()=="X" ||ui->Btn2->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn2->setText("X");
    }else{
        ui->Btn2->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn3Clicked()
{
    if(ui->Btn3->text()=="X" ||ui->Btn3->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn3->setText("X");
    }else{
        ui->Btn3->setText("O");
    }
    count++;
    Check();

}

void secondwindow::OnBtn4Clicked()
{
    if(ui->Btn4->text()=="X" ||ui->Btn4->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn4->setText("X");
    }else{
        ui->Btn4->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn5Clicked()
{
    if(ui->Btn5->text()=="X" ||ui->Btn5->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn5->setText("X");
    }else{
        ui->Btn5->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn6Clicked()
{
    if(ui->Btn6->text()=="X" ||ui->Btn6->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn6->setText("X");
    }else{
        ui->Btn6->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn7Clicked()
{
    if(ui->Btn7->text()=="X" ||ui->Btn7->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn7->setText("X");
    }else{
        ui->Btn7->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn8Clicked()
{
    if(ui->Btn8->text()=="X" ||ui->Btn8->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn8->setText("X");
    }else{
        ui->Btn8->setText("O");
    }
    count++;
    Check();
}

void secondwindow::OnBtn9Clicked()
{
    if(ui->Btn9->text()=="X" ||ui->Btn9->text()=="O" )
    {
        QMessageBox::warning(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->Btn9->setText("X");
    }else{
        ui->Btn9->setText("O");
    }
    count++;
    Check();
}
