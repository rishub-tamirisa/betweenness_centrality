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
  NodeReader reader("225FPDataset/test.txt");
  reader.readInEdgeList(graph);
  // graph.calc_forces();
  graph.draw_graph(500, 500);
  //graph.BFS();
  return 0;
}
