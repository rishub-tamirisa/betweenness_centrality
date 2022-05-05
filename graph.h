#pragma once
#include <vector>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <map>
#include <tuple>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>

class Graph {
    public:
        class Edge; // forward declaration

        class Vertex {
            public:
                int ID;
                int degree;
                std::list<Edge*> edges;
                Vertex(int id) : ID(id), degree(0) {}
        };

        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                Edge(Vertex* _v1, Vertex* _v2, int w) : weight(w), v1(_v1), v2(_v2) {}
        };

        void insertVertex(int key);

        void insertEdge(int k1, int k2, int w);

        std::list<Edge*> incidentEdges(int key);

        bool areAdjacent(int k1, int k2);


        //access vertices
        Vertex* operator[](int key) { return adj_list.at(key); }

        //BFS
        std::vector<int> BFS(int root, int target);

        void Brandes_BFS_helper(int s, std::unordered_map<int,std::vector<int>>& pred, 
                        std::unordered_map<int, int>& sigma, std::stack<int>& stack);


        std::vector<std::pair<int, double>> betweenness_centrality(int k);
        
        bool map_compare(std::pair<int, double>& a, std::pair<int, double>& b);

        Graph connected_subgraph(int root, int size, bool write);

        //FORCE-DIRECTED DRAWING

        void draw_graph();

        ~Graph();
        
        //testing purposes
        std::unordered_map<int, Vertex*>& getAdjList() { return adj_list; }

        std::vector<Edge*>& getEdgeList() { return edge_list; }

    private:

        std::unordered_map<int, Vertex*> adj_list;
        std::vector<Edge*> edge_list;

};