#include "graph.h"
#include <algorithm>
#include <queue>
#include <iostream>
//O(1)
//test-Rishub
//test merge branch
void Graph::insertVertex(int key) {
    if (adj_list.find(key) == adj_list.end()) {
        adj_list[key] = new Vertex(key);
    }
}

//O(max(deg(v1), deg(v2))) ~ O(1)
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

//O(1)
std::list<Graph::Edge*> Graph::incidentEdges(int key) {
    return adj_list[key]->edges;
}

//O(max(deg(v1), deg(v2))) ~ O(1)
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

std::vector<int> Graph::BFS(int root, int target) {
    std::queue<int> q;
    std::unordered_map<int, int> path;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == target) {
            break;
        }
        for (auto edge : adj_list[front]->edges) {
            int neighbor = edge->v1->ID == front ? edge->v2->ID : edge->v1->ID;
            if (path.find(neighbor) == path.end()) {
                q.push(neighbor);
                path[neighbor] = front;
            } 
        }
    }
    std::vector<int> result;
    while (target != root) {
        result.push_back(target);
        target = path[target];
    }
    result.push_back(root);
    std::reverse(result.begin(), result.end());
    return result;
}


//O(V+E)
Graph::~Graph() {
    for (Edge* edge : edge_list) {
        delete edge;
    }
    for (auto v : adj_list) {
        delete v.second;
    }
}

