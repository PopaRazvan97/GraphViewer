#ifndef GRAPH_H
#define GRAPH_H
#include "edges.h"
#include <QFile>
#include <QTextStream>
#include <vector>

using namespace std;
class Graph {
public:
    Graph();
    void AddNode(Node n);
    void AddEdge(Edge a);
    int GetNumberOfNodes();
    vector<Node> GetNodes();
    vector<Edge> GetEdges();
    void WriteInFile(vector<vector<int>> Matrix);
    void UpdateMatrix();
    bool VerifyOverlay(Node n);

private:
    vector<Node> m_nodes;
    vector<Edge> m_edges;
    vector<vector<int>> m_matrix;
};

#endif // GRAPH_H
