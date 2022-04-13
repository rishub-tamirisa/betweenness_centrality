#include "NodeReader.h"

NodeReader::NodeReader(std::string& filename) {

}
        
void NodeReader::readInEdgeList(Graph& graph) {

}

void NodeReader::readInLabels(std::string& filename) {

}

std::string  NodeReader::getLabel(int NodeID) {
    return labels_hash[NodeID];
}
