#pragma once
#include <vector>

class Graph {
    public:
        class Vertex {
            public:
                int key;
                Vertex(int k) : key(k) {}
        };

        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                Edge(Vertex* v1, Vertex* v2, int w) : weight(w) {}
        };

        void insertVertex(int key);

        void insertEdge(Vertex* v1, Vertex* v2, int w);

        std::vector<Edge> incidentEdges(Vertex* v);

        bool areAdjacent(Vertex* v1, Vertex* v2);

    private:
        int t;
};