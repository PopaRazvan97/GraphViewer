#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include "node.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* ev);
    void paintEvent(QPaintEvent* p);
    void on_NeorientatButton_released();
    void on_OrientatButton_released();
    void drawLineWithArrow(QPainter& painter, QPointF start, QPointF end);
    ~MainWindow();
//private slots:
//    void on_radioButton_released();

private:
    Graph graph;
    Ui::MainWindow *ui;
    const int nodeRadius = 10;
    bool isFirstNode;
    Node firstNode;
};
#endif // MAINWINDOW_H
