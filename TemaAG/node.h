#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <cmath>
class Node
{
public:
    Node();
    Node(const QPointF& coordinates);
    Node(int value, const QPointF& coordinates);
    Node(const Node& node);

public:
    Node& operator=(const Node& node);
    bool operator==(const Node& node);
    void SetValue(int value);
    void SetCoordinates(const QPointF& coordinates);
    int GetValue() const;
    QPointF GetCoordinates() const;

public:
    float Distance(const QPointF& coordinates) const;
    float Distance(const Node& node) const;

private:
    int m_value;
    QPointF m_coordinates;
};

#endif // NODE_H
