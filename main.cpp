/**
 * @file main.cpp
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "graph.h"
#include "NodeReader.h"

int main() {
  Graph graph;
  NodeReader reader("225FPDataset/com-amazon.ungraph.txt");
  reader.readInEdgeList(graph);
  //graph.BFS();
  return 0;
}
