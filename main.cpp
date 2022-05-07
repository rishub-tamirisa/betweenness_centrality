/**
 * @file main.cpp
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "graph.h"
#include "NodeReader.h"

int main(int argc, char** argv) {
  //Example Input: ./graph "225FPDataset/com-amazon-reduced.ungraph.txt" "225FPDataset/amazon-meta-reduced.txt" "" 100000 500 10 500 500 1 404753
  //Example Input with no Labels: ./graph "225FPDataset/com-amazon-reduced.ungraph.txt" "" "" 100000 500 10 500 500 1 404753

  /*
  * Command Line Argument Validation
  */
  if (argc == 2) {
    std::string input = argv[1];
    if (input == "help") {
      std::cout << "Use ./graph [input loc] [input labels] [output loc] [starting node] [size] [# of BC vals] [img x dim] [img y dim] [BFS start ID] [BFS end ID]" << std::endl;
    } else {
      std::cout << "Use ./graph 'help' to display the input options for this executable." << std::endl;
    }
    return 0;
  }
  if (argc != 11) {
    std::cout << "Invalid Arguments. Use ./graph [input loc] [input labels] [output loc] [starting node] [size] [# of BC vals] [img x dim] [img y dim] [BFS start ID] [BFS end ID]" << std::endl;
    std::cout << "\nUse \"\" for [output loc] to specify the general directory as the output location" << std::endl;
    std::cout << "\nUse \"\" for [input labels] if there are no labels" << std::endl;
    return 0;
  }
  std::vector<std::string> args;
  std::cout << "Your input: ";
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
    std::cout << args[i] << " ";
  }
  std::cout << "\n";

  /*
  * Read in Graph
  */
  Graph graph;
  NodeReader reader(args[1]);
  reader.readInEdgeList(graph);
  reader.readInLabels(args[2]);

  Graph sub = graph.connected_subgraph(std::stoi(args[4]), std::stoi(args[5]));

  auto BC = sub.betweenness_centrality(std::stoi(args[6]));

  /*
  * Betweenness Centrality Output
  */
  std::cout << "---------------------------------------\n"; 
  std::cout << "        Betweenness Centrality\n";
  std::cout << "---------------------------------------\n"; 
  for (unsigned i = 0; i < BC.size(); i++ ) {
    auto pair = BC[i];
    std::cout << "#" << i + 1 << ": ";
    if (args[2] != "") {
      std::cout << "Product: " << reader[pair.first] << " | "; 
    }
      std::cout << " Node: " << pair.first << " | Centrality: " << pair.second << std::endl;
  }
  std::cout << "\n";

  sub.draw_graph(args[3], std::stoi(args[7]), std::stoi(args[8]), false);
  std::string loc = args[3];
  if (loc != "") {
    loc = loc + "/";
  }

  /*
  * Force-Directed Drawing Output
  */
  std::cout << "---------------------------------------\n"; 
  std::cout << "         Force-Directed Drawing\n";
  std::cout << "---------------------------------------\n";

  std::cout << "Graph Drawn and stored at " << loc << "GraphDrawn_Size" << args[5] << ".svg\n" << std::endl;

  /*
  *  BFS Path Output
  */
  std::cout << "---------------------------------------\n"; 
  std::cout << "              BFS Path\n";
  std::cout << "---------------------------------------\n";

  std::vector<int> path = graph.BFS(std::stoi(args[9]), std::stoi(args[10]));

  for (unsigned i = 0; i < path.size(); i++) {
    if (args[2] == "") {
      std::cout << path[i];
    } else {
      std::cout << reader[path[i]] << " (" << path[i] << ") "; 
    }
    if (i < path.size() - 1) {
      std::cout << " --> ";
    }
  }
  std::cout << "\n\n";

  return 0;
}
