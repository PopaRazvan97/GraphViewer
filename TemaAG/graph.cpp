#include "graph.h"

Graph::Graph()
{

}

void Graph::AddNode(Node n)
{
    m_nodes.push_back(n);
}

void Graph::AddEdge(Edge a)
{
    m_edges.push_back(a);
}

int Graph::GetNumberOfNodes()
{
    return (int)m_nodes.size();
}
vector<Node> Graph::GetNodes()
{
    return m_nodes;
}

vector<Edge> Graph::GetEdges()
{
    return m_edges;
}

void Graph::WriteInFile(vector<vector<int>> m_matrix)
{
    QFile file("C:/Users/razvy/Downloads/tema agg1/AoloooGucci/Matrix.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        for (auto i = 0; i < m_matrix.size(); i++) {
            for (auto j = 0; j < m_matrix[0].size(); j++)
                stream << m_matrix[i][j] << " ";
            stream << '\n';
        }
    }
    file.close();
}

void Graph::UpdateMatrix() {
    m_matrix.resize(m_nodes.size());
    for (int i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(m_nodes.size());
        for (int j = 0; j < m_matrix[0].size(); j++)
            m_matrix[i][j] = 0;
    }
    for (int i = 0; i < m_edges.size(); i++) {
        m_matrix[m_edges[i].GetFirstNode().GetValue() - 1]
                [m_edges[i].GetSecondNode().GetValue() - 1] = 1;
    }
    WriteInFile(m_matrix);
}

bool Graph::VerifyOverlay(Node n)
{
    for (auto it : m_nodes)
        if (n.Distance(it) < 20)
            return false;
    return true;
}
