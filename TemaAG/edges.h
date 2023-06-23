#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
public:
    Edge();
    Edge(Node firstNode, Node secondNode);
    Node GetFirstNode();
    Node GetSecondNode();

private:
    Node m_firstNode, m_secondNode;
};

#endif // EDGE_H
