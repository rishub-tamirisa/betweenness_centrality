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
  NodeReader reader("225FPDataset/com-amazon-reduced.ungraph.txt");
  reader.readInEdgeList(graph);
  Graph sub = graph.connected_subgraph(49956, 100, true);
  // NodeReader reader("connected_size_300.txt");
  // reader.readInEdgeList(graph);
  sub.betweenness_centrality(10);
  sub.draw_graph(1000, 1000, false);

  return 0;
}
