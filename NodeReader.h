#pragma once
#include "graph.h"
#include <unordered_map>
#include <string>

/**
* NodeReader Class: read in the NodeID file format provided with the SNAP dataset
* - supports reading the full Edgelist into our Graph ADT
* - stores the labels for each nodeID that can be used to properly interpret the Graph
*/
class NodeReader {
    public:
        /**
        * @name NodeReader
        * initializa a NodeReader with the filename of the data file
        */
        NodeReader(std::string filename);
        
        /**
        * @name readInEdgeList
        * build a graph from the data file that the NodeReader was initialized with
        * @param graph the graph to build
        */
        void readInEdgeList(Graph& graph);

        /**
        * @name readInLabels
        * store labels for NodeIDs
        * @param filename the file containing the labels
        */
        void readInLabels(std::string filename);

        /**
        * @name operator[]
        * [] operator overload to easily access labels given NodeIDs
        * @param key the key of the vertex
        * @return a string containing the label
        */
        std::string& operator[](int key) { return labels_hash.at(key); }

        /**
        * @name getLabels
        * returns the labels hashmap. Used only for testing purposes
        * @return the labels hashmap
        */
        std::unordered_map<int, std::string>& getLabels() { return labels_hash; }

    private:
        /**
        * @name labels_hash
        * a hash_map storing NodeID keys and label strings
        */
        std::unordered_map<int, std::string> labels_hash;

        /**
        * @name src_file
        * the file of the data directory
        */
        std::string src_file;
};