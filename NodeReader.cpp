#include "NodeReader.h"
#include <iostream>

NodeReader::NodeReader(std::string& filename) {
        src_file = filename;
}
        
void NodeReader::readInEdgeList(Graph& graph) {

}

void NodeReader::readInLabels(std::string& filename) {

}

std::string  NodeReader::getLabel(int NodeID) {
    return labels_hash[NodeID];
}
