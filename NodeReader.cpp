#include "NodeReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

NodeReader::NodeReader(std::string filename) {
        src_file = filename;
}
        
void NodeReader::readInEdgeList(Graph& graph) {
    std::ifstream file;
    file.open(src_file);
    std::stringstream sstream;
    std::string line;
    int FromNodeID, ToNodeID;
    std::unordered_map<int, int> duplicate_vertex;
    std::map<std::pair<int, int>, int> duplicate_edge;

    if (file.is_open()) {
        while (getline(file, line)) {
            sstream << line;
            sstream >> FromNodeID >> ToNodeID;
            sstream.clear();
            graph.insertVertex(FromNodeID);
            graph.insertVertex(ToNodeID);
            graph.insertEdge(FromNodeID, ToNodeID, 1);

            // Use below code to automate REQUIRE statements for testcases
            // std::cout << "REQUIRE(graph.areAdjacent(" << FromNodeID << ", " << ToNodeID << "));" << std::endl;

        }
        file.close();
    }
}

void NodeReader::readInLabels(std::string filename) {

}

std::string  NodeReader::getLabel(int NodeID) {
    return labels_hash[NodeID];
}
