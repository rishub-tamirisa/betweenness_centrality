#pragma once
#include "graph.h"
#include <unordered_map>
#include <string>

/**
* Class to read in the NodeID file format provided with the SNAP dataset
* - supports reading the full Edgelist into our Graph ADT
* - stores the labels for each nodeID that can be used to properly interpret the Graph
*/
class NodeReader {
    public:
        NodeReader(std::string filename);
        
        void readInEdgeList(Graph& graph);

        void readInLabels(std::string filename);

        std::string getLabel(int NodeID);
    private:
        std::unordered_map<int, std::string> labels_hash;
        std::string src_file;
};