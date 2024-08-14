#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , selectedShape(nullptr)
{
    ui->setupUi(this);
    paintWindow = new QImage(ui->PaintBox->size(), QImage::Format_RGB32);
    paintWindow->fill(Qt::white);
    ui->PaintBox->setPixmap(QPixmap::fromImage(*paintWindow));

    connect(ui->SquareBtn, &QPushButton::clicked, this, &MainWindow::OnSquareBtnClicked);
    connect(ui->SelectBtn, &QPushButton::clicked, this, &MainWindow::OnSelectBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete paintWindow;
}

void MainWindow::OnSquareBtnClicked()
{
    currentShape = Square;
}

void MainWindow::OnSelectBtnClicked()
{
    currentShape = Select;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint clickPos = ui->PaintBox->mapFrom(this, event->pos());
    if (event->button() == Qt::LeftButton)
    {
        if (currentShape == Select)
        {
            selectedShape = nullptr;
            for (ShapeInfo &shapeInfo : shapes)
            {
                if (shapeInfo.rect.contains(clickPos))
                {
                    selectedShape = &shapeInfo;
                    offset = clickPos - shapeInfo.rect.topLeft();

                    if (abs(clickPos.x() - shapeInfo.rect.right()) < 5 && abs(clickPos.y() - shapeInfo.rect.bottom()) < 5)
                    {
                        resizingShape = true;
                    }
                    else
                    {
                        movingShape = true;
                    }
                    break;
                }
            }
        }
        else if (currentShape == Square)
        {
            drawing = true;
            startPosition = clickPos;
            endPosition = clickPos;
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint movePos = ui->PaintBox->mapFrom(this, event->pos());
    if (drawing && currentShape == Square)
    {
        endPosition = movePos;
        update();
    }
    else if (movingShape && selectedShape)
    {
        selectedShape->rect.moveTo(movePos - offset);
        update();
    }
    else if (resizingShape && selectedShape)
    {
        selectedShape->rect.setBottomRight(movePos);
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (drawing && currentShape == Square)
    {
        drawing = false;
        ShapeInfo newShape;
        newShape.rect = QRect(startPosition, endPosition);
        shapes.append(newShape);
        update();
    }
    else if (movingShape || resizingShape)
    {
        movingShape = false;
        resizingShape = false;

        paintWindow->fill(Qt::white);
        QPainter painter(paintWindow);
//        for (const ShapeInfo &shape : shapes)
//        {
//            painter.drawRect(shape.rect);
//        }
        ui->PaintBox->setPixmap(QPixmap::fromImage(*paintWindow));
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);

    painter.drawImage(ui->PaintBox->pos(), *paintWindow);

    if (drawing && currentShape == Square)
    {
        QImage tempImage = *paintWindow;
        QPainter tempPainter(&tempImage);
        tempPainter.drawRect(QRect(startPosition, endPosition));
        ui->PaintBox->setPixmap(QPixmap::fromImage(tempImage));
    }

    if (selectedShape)
    {
        QPen highlightPen(Qt::blue);
        highlightPen.setStyle(Qt::DotLine);
        highlightPen.setWidth(2);

        QPixmap pixmap = ui->PaintBox->pixmap()->copy();
        QPainter labelPainter(&pixmap);
        labelPainter.setPen(highlightPen);
        labelPainter.drawRect(selectedShape->rect);
        ui->PaintBox->setPixmap(pixmap);
    }
}
