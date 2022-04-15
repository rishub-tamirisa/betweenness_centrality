/**
 * @file main.cpp
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "graph.h"

int main() {
  Graph graph;
  NodeReader reader("225FPDataset/test.txt");
  reader.readInEdgeList(graph);
  //graph.BFS();
  return 0;
}
