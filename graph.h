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
/**
* Graph class: Implemented using an adjacency list and edge list, and
* uses Vertex and Edge private classes to manage data
*/
class Graph {
    public:
        class Edge;

        /** 
        * Vector Class: Defines a 2D Mathematical Vector for use in Force-Directed Graph Drawing.
        * Supports Vector Addition, Subtraction, Scalar Multiplication and Addition
        */
        class Vector {
            public:
                float x;
                float y;
                Vector(float _x, float _y) : x(_x), y(_y) {}
                Vector() : x(0), y(0) {}

                /**
                * @name mag 
                * Calculates the magnitude of the Vector
                * @return magnitude of Vector
                */
                float mag() { return std::sqrt(x*x + y*y); }

                /**
                * @name operator+ 
                * Adds two Vectors
                * @return resultant Vector
                */
                Vector operator+(const Vector& v2) {return Vector(x + v2.x, y + v2.y); }
               
                /**
                * @name operator- 
                * Subtracts two Vectors
                * @return resultant Vector
                */
                Vector operator-(const Vector& v2) {return Vector(x - v2.x, y - v2.y); }

                /**
                * @name operator/ 
                * Divides Vector by a scalar
                * @return resultant Vector
                */
                Vector operator/(const float scalar) {return Vector(x / scalar, y / scalar); }

                /**
                * @name operator*
                * Multiplies Vector by a scalar
                * @return resultant Vector
                */
                Vector operator*(const float scalar) {return Vector(x * scalar, y * scalar); }
        };

        /**
        * Vertex Class: Defines a vertex in graph theory, stores relevant attributes for functions,
        * edge list, and degree
        */
        class Vertex {
            public:
                Vector pos;
                Vector disp;
                int centrality;
                int color;
                int ID;
                int degree;
                std::list<Edge*> edges;

                /**
                * @name Vertex
                * Define a Vector with an ID
                */
                Vertex(int id) : centrality(0), color(0), ID(id), degree(-1) {
                    Vector disp_temp(0,0);
                    disp = disp_temp;
                }
        };

        /**
        * Edge Class: Defines an edge in graph theory, stores a weight and two vertices
        */
        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                
                /**
                * @name Edge
                * Define an Edge with two Vertices and a weight
                */
                Edge(Vertex* _v1, Vertex* _v2, int w) : weight(w), v1(_v1), v2(_v2) {}
        };
        

        /**
        * @name insertVertex
        * inserts a vertex into the Graph ADT
        * Runs in O(1)
        * @param key the key of the vertex to be inserted
        */
        void insertVertex(int key);

        /**
        * @name insertEdge
        * inserts an edge into the Graph ADT
        * @param k1 a key on one side of the edge
        * @param k2 a key on one side of the edge
        * @param w the weight of the edge
        * Runs in O(max(deg(v1), deg(v2)))
        */
        void insertEdge(int k1, int k2, int w);

        /**
        * @name incidentEdges
        * inserts an edge into the Graph ADT
        * @param key the vertex whose edges are being returned
        * @return a list of Edge pointers
        * Runs in O(1)
        */
        std::list<Edge*> incidentEdges(int key);

        /**
        * @name areAdjacent
        * checks if two vertices are Adjacent
        * @param k1 the key of the first vertex to check
        * @param k2 the key of the second vertex to chec
        * @return a bool specifying if the input keys are adjacent
        * Runs in O(max(deg(v1), deg(v2))) ~ O(1)
        */
        bool areAdjacent(int k1, int k2);

        /**
        * @name BFS
        * find the shortest path between two vertices
        * @param root the key of the first vertex in the path
        * @param target the key of the last vertex in the path
        * @return a vector of keys following the path from root to target
        * Runs in O(V+E)
        */
        std::vector<int> BFS(int root, int target);

        /**
        * @name betweennes_centrality
        * determine the centrality of nodes in the graph.
        * An implementation of the Brandes Algorithm for betweenness centrality described in the 
        * original Brandes algorithm paper (Algorithm 1)
        * Brandes, U. 2001. A Faster Algorithm for Betweenness Centrality. Journal of Mathematical Sociology, 163--177.
        * @param k the number of nodes to return for centrality output
        * @return a vector of k pairs of node IDs and their centralities
        * Runs in O(V^2)
        */
        std::vector<std::pair<int, float>> betweenness_centrality(int k);
        
        /**
        * @name connected_subgraph
        * find a connected subgraph within the overall graph, knowing the graph is fully connected
        * @param root the node to generate the subgraph from
        * @param size the number of nodes in the subgraph
        * @return a subgraph starting from root of size: size
        * Runs in O(V+E)
        */
        Graph connected_subgraph(int root, int size);

        /**
        * @name draw_graph
        * draw the graph within a specified name, and output in SVG format to a specified file location
        * @param loc the file location to save the SVG to
        * @param width the width of the output frame
        * @param height the height of the output frame
        * @param ID bool for whether to display node IDs
        * Runs in O(V^2)
        */
        void draw_graph(std::string loc, int width, int height, bool ID);

        /**
        * @name ~Graph
        * clears the memory associated with the graph
        * Runs in O(V+E)
        */
        ~Graph();
        
        /**
        * @name getAdjList
        * returns the adjacency list. Used only for testing purposes
        * @return the adjacency list
        */
        std::unordered_map<int, Vertex*>& getAdjList() { return adj_list; }

        /**
        * @name getEdgeList
        * returns the edge list. Used only for testing purposes
        * @return the edge list
        */
        std::vector<Edge*>& getEdgeList() { return edge_list; }

    private:
        /**
        * @name bc_computed
        * bool that keeps track of when betweenness centrality is computed
        */
        bool bc_computed = false;

        /**
        * @name adj_list
        * a hashmap adjacency list from keys to Vertex pointers
        */
        std::unordered_map<int, Vertex*> adj_list;

        /**
        * @name edge_list
        * a vector edge list of Edge pointers
        */
        std::vector<Edge*> edge_list;
        
        /**
        * @name Brandes_BFS_helper
        * a BFS implementation the finds all shortests paths from a specified starting node to every other node.
        * follows the BFS algorithm described in the original Brandes algorithm paper (Algorithm 1)
        * Brandes, U. (2001). A Faster Algorithm for Betweenness Centrality. Journal of Mathematical Sociology (p./pp. 163--177)
        */
        void Brandes_BFS_helper(int s, std::unordered_map<int,std::vector<int>>& pred, std::unordered_map<int, int>& sigma, std::stack<int>& stack);

        /**
        * @name calc_forces
        * Calculates the attractive and repulsive forces on graph vertices to convergence.
        * An altered implementation of the Fruchterman and Reingold Force Directed Graph Drawing n-body algorithm
        * Thomas M. J. Fruchterman and Edward M. Reingold. 1991. Graph drawing by force-directed placement. Softw. Pract. 
        *   Exper. 21, 11 (Nov. 1991), 1129–1164. https://doi.org/10.1002/spe.4380211102
        * @param width the width of the frame
        * @param height the height of the frame
        */
        void calc_forces(float width, float height);

        /**
        * @name init_pos
        * randomly initialize Vertex position vectors within the frame
        * @param width the width of the frame
        * @param height the height of the frame
        */
        void init_pos(int width, int height);

        /**
        * @name set_dims
        * rescales the x and y dimensions of the SVG frame in the draw_graph function to fit the
        * maximum and minimum vertex positions found by Fruchterman Reingold. Adjusts vertex positions 
        * to fit in bounds
        * @param width the frame width to be modified
        * @param height the frame height to be modified
        */
        void set_dims(int& width, int& height);
        
        /**
        * @name normalize_bc
        * normalize the betweenness centrality values within a reasonable range. Assigns vertex colors based 
        * on their centralities for better graph drawing output
        */
        void normalize_bc();
};