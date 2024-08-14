#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QVector>
#include <QRect>
#include <QColorDialog>

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
    void OnSquareBtnClicked();
    void OnSelectBtnClicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
    QImage *paintWindow;
    bool drawing;
    bool movingShape;
    QPoint startPosition;
    QPoint endPosition;
    QPoint offset;
    bool resizingShape = false;

    enum Shape { None, Square, Select };
    Shape currentShape;

    struct ShapeInfo
    {
        QRect rect;
        bool isSelected;
    };

    QVector<ShapeInfo> shapes;
    ShapeInfo* selectedShape;
};

#endif // MAINWINDOW_H
