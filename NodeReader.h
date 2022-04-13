#pragma once
#include <vector>
#include <map>
#include "graph.h"
#include <unordered_map>
using namespace std;

class NodeReader {
    public:
        NodeReader(string& filename);
        
        void readInEdgeList(Graph& graph);

        void readInLabels(string& filename);
    private:
        unordered_map<int, string> labels_hash;
        string src_file;
};