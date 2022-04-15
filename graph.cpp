#include "graph.h"
#include <algorithm>

void Graph::insertVertex(int key) {
    if (adj_list.find(key) == adj_list.end()) {
        adj_list[key] = new Vertex();
    }
}

void Graph::insertEdge(int k1, int k2, int w) {
    if (adj_list.find(k1) != adj_list.end() && adj_list.find(k2) != adj_list.end()) {
        Vertex* v = adj_list[k1];
        Vertex* v2 = adj_list[k2];
        if (adj_list[k2]->degree <= adj_list[k1]->degree) {
            v = adj_list[k2];
            v2 = adj_list[k1];
        }
        for (auto edge : v->edges) {
            if (edge->v1 == v2 || edge->v2 == v2) {
                return; // edge already exists
            }
        }

        Edge* edge = new Edge(adj_list[k1], adj_list[k2], w);
        edge_list.push_back(edge);
        adj_list[k1]->edges.push_front(edge);
        adj_list[k1]->degree++;
        adj_list[k2]->edges.push_front(edge);
        adj_list[k2]->degree++;
    }
}

std::list<Graph::Edge*> Graph::incidentEdges(int key) {
    return adj_list[key]->edges;
}

bool Graph::areAdjacent(int k1, int k2) {
    if (adj_list.find(k1) != adj_list.end() && adj_list.find(k2) != adj_list.end()) {
        Vertex* v1 = adj_list[k1];
        Vertex* v2 = adj_list[k2];
        Vertex* v = v2;
        if (v1->degree <= v2->degree) {
            v = v1;
        }
        for(auto edge : v->edges) {
            if ((edge->v1 == v1 && edge->v2 == v2) || (edge->v1 == v2 && edge->v2 == v1)) {
                return true;
            }
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

