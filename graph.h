#pragma once
#include <vector>
#include <unordered_map>
class Graph {
    public:
        class Vertex {
            public:
                int key;
                int degree;
                Vertex(int k) : key(k) {}
        };

        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                Edge(Vertex* _v1, Vertex* _v2, int w) : weight(w), v1(_v1), v2(_v2) {}
        };

        void insertVertex(int key);

        void insertEdge(Vertex* v1, Vertex* v2, int w);

        std::vector<Edge> incidentEdges(Vertex* v);

        bool areAdjacent(Vertex* v1, Vertex* v2);

    private:
        std::unordered_map<Vertex*, Edge> adj_list;
};