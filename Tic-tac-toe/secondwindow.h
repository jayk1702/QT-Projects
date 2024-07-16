#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr,QString P1name = "", QString P2name = "");
    ~secondwindow();
    void Check();

public slots:
    void OnBtn1Clicked();

    void OnBtn2Clicked();

    void OnBtn3Clicked();

    void OnBtn4Clicked();

    void OnBtn5Clicked();

    void OnBtn6Clicked();

    void OnBtn7Clicked();

    void OnBtn8Clicked();

    void OnBtn9Clicked();

private:
    Ui::secondwindow *ui;
    int count=1;
    QString player1Name;
    QString player2Name;
};

#endif // SECONDWINDOW_H
