#include "node.h"

Node::Node(): m_value(), m_coordinates(0, 0)
{

}

Node::Node(const QPointF& coordinates): m_coordinates(coordinates)
{

}

Node::Node(int value, const QPointF& coordinates): m_value(value), m_coordinates(coordinates)
{

}

Node::Node(const Node& node): m_value(node.m_value), m_coordinates(node.m_coordinates)
{

}

Node& Node::operator= (const Node& node)
{
    m_value=node.m_value;
    m_coordinates=node.m_coordinates;
    return *this;
}
bool Node::operator==(const Node& node)
{
    return m_value == node.m_value && m_coordinates == node.m_coordinates;
}

void Node::SetValue(int value)
{
    m_value=value;
}

void Node::SetCoordinates(const QPointF& coordinates)
{
    m_coordinates=coordinates;
}

int Node::GetValue() const
{
    return m_value;
}

QPointF Node::GetCoordinates() const
{
    return m_coordinates;
}

float Node::Distance(const QPointF& coordinates) const
{
    float a, b;
    a=std::pow(coordinates.x() - m_coordinates.x(), 2);
    b=std::pow(coordinates.y() - m_coordinates.y(), 2);
    return std::sqrt(a+b);
}

float Node::Distance(const Node& node) const
{
    return Distance(node.m_coordinates);
}
