#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMouseEvent>
#include <QPainter>
#include <QTextStream>
#include <algorithm>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    //ui->OrientatButton->setChecked(true);
    ui->setupUi(this);
    ui->NeorientatButton->setChecked(true);
    isFirstNode = false;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::RightButton) {
        Node n(ev->position());
        // verificare suprapunere
        if (graph.VerifyOverlay(n)) {
            n.SetValue(graph.GetNumberOfNodes() + 1);
            graph.AddNode(n);
            update();
            graph.UpdateMatrix();
        }
    } else if (ev->button() == Qt::LeftButton) {
        vector<Node> nodes = graph.GetNodes();
        Node selected;
        bool ok = false;
        for (Node &n : nodes) {
            QPointF coord = n.GetCoordinates();
            float dist = sqrt(
                        (ev->position().x() - coord.x()) * (ev->position().x() - coord.x()) +
                        (ev->position().y() - coord.y()) * (ev->position().y() - coord.y()));

            if (dist <= nodeRadius) {
                selected = n;
                ok = true;
                break;
            }
        }

        if (ok) {
            if (!isFirstNode) {
                firstNode = selected;
                isFirstNode = true;
            } else {
                std::vector<Edge> edges = graph.GetEdges();
                Edge a = Edge(firstNode, selected);
                bool ok = false;
                for (auto it : edges) {
                    if (it.GetFirstNode().GetValue() == a.GetFirstNode().GetValue() &&
                            it.GetSecondNode().GetValue() == a.GetSecondNode().GetValue())
                        ok = true;
                }
                if (ok == false) {
                    graph.AddEdge(Edge(firstNode, selected));
                    if(ui->NeorientatButton->isChecked())
                    graph.AddEdge(Edge(selected, firstNode));
                    isFirstNode = false;
                    update();
                    graph.UpdateMatrix();
                }
            }
        } else {
            isFirstNode = false;
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);

    vector<Node> nodes = graph.GetNodes();
    for (Node &n : nodes) {
        QPointF coord = n.GetCoordinates();
        QRect r(coord.x() - nodeRadius, coord.y() - nodeRadius, 2 * nodeRadius,
                2 * nodeRadius);
        QPen pen;
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawEllipse(r);
        QString num = QString::number(n.GetValue());
        p.drawText(r, Qt::AlignCenter, num);
    }
    vector<Edge> edges = graph.GetEdges();
    for (Edge &e : edges) {
        //aici bagi drawArrow
        drawLineWithArrow(p, e.GetFirstNode().GetCoordinates(),e.GetSecondNode().GetCoordinates());
    }
}

void MainWindow::drawLineWithArrow(QPainter& painter, QPointF start, QPointF end)

{
    painter.setRenderHint(QPainter::Antialiasing, true);
    qreal arrowSize = 10; // size of head
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    QLineF line(end, start);
    double angle = std::atan2(-line.dy(), line.dx());

    QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,

                                          cos(angle + M_PI / 3) * arrowSize);

    QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,

                                          cos(angle + M_PI - M_PI / 3) * arrowSize);
    QPolygonF arrowHead;
    arrowHead.clear();
    arrowHead << line.p1() << arrowP1 << arrowP2;
    painter.drawLine(line);
    painter.drawPolygon(arrowHead);
}

MainWindow::~MainWindow() { delete ui; }

//void MainWindow::on_radioButton_released() {

//}
