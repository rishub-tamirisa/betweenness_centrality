#include "graph.h"
#include <algorithm>

void Graph::insertVertex(int key) {
    adj_list[key] = new Vertex();
}

void Graph::insertEdge(Graph::Vertex* v1, Graph::Vertex* v2, int w) {
    Edge* edge = new Edge(v1, v2, w);
    edge_list.push_back(edge);
    v1->edges.push_front(edge);
    v1->degree++;
    v2->edges.push_front(edge);
    v2->degree++;
}

std::list<Graph::Edge*> Graph::incidentEdges(Graph::Vertex* v) {
    return v->edges;
}

bool Graph::areAdjacent(Graph::Vertex* v1, Graph::Vertex* v2) {
    Vertex* v = v2;
    if (v1->degree <= v2->degree) {
        v = v1;
    }
    for(auto edge : v->edges) {
        if ((edge->v1 == v1 && edge->v2 == v2) || (edge->v1 == v2 && edge->v2 == v1)) {
            return true;
        }
    }
    return false;
}

Graph::~Graph() {
    for (Edge* edge : edge_list) {
        delete edge;
    }
    for (auto v : adj_list) {
        delete v.second;
    }
}
