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
#include <cmath>

class Graph {
    public:
        class Edge; // forward declaration

        class Vector {
            public:
                float x;
                float y;
                Vector(float _x, float _y) : x(_x), y(_y) {}
                Vector() : x(0), y(0) {}
                float mag() { return std::sqrt(x*x + y*y); }
                Vector operator+(const Vector& v2) {return Vector(x + v2.x, y + v2.y); }
                Vector operator-(const Vector& v2) {return Vector(x - v2.x, y - v2.y); }
                Vector operator/(const float scalar) {return Vector(x / scalar, y / scalar); }
                Vector operator*(const float scalar) {return Vector(x * scalar, y * scalar); }


        };

        class Vertex {
            public:
                Vector pos;
                Vector disp;
                int centrality;
                int color;
                int ID;
                int degree;
                std::list<Edge*> edges;
                Vertex(int id) : centrality(0), color(0), ID(id), degree(-1) {
                    Vector disp_temp(0,0);
                    disp = disp_temp;
                }
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


        std::vector<std::pair<int, float>> betweenness_centrality(int k);
        
        bool map_compare(std::pair<int, float>& a, std::pair<int, float>& b);

        Graph connected_subgraph(int root, int size, bool write);

        //FORCE-DIRECTED DRAWING

        void draw_graph(int x, int y, bool ID);

        void calc_forces(float x, float y);

        void init_pos(int x, int y);

        void set_dims(int& x, int& y);

        ~Graph();
        
        //testing purposes
        std::unordered_map<int, Vertex*>& getAdjList() { return adj_list; }

        std::vector<Edge*>& getEdgeList() { return edge_list; }

        void normalize_bc();


    private:
        bool bc_computed = false;
        std::unordered_map<int, Vertex*> adj_list;
        std::vector<Edge*> edge_list;



};