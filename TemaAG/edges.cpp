#include "edges.h"

Edge::Edge(): m_firstNode(), m_secondNode()
{

}
Edge::Edge(Node firstNode, Node secondNode): m_firstNode(firstNode), m_secondNode(secondNode)
{

}
Node Edge::GetFirstNode()
{
    return m_firstNode;
}
Node Edge::GetSecondNode()
{
    return m_secondNode;
}
