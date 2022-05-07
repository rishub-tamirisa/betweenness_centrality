#include "catch.hpp"

#include <string>
#include <iostream>
#include <vector>
#include "graph.h"
#include "NodeReader.h"

bool match_vec(std::vector<int>& first, std::vector<int>& second) {
   for (unsigned i = 0; i < first.size(); i++) {
      if (i >= second.size() || first[i] != second[i]) {
         return false;
      }
   }
   return true;
}

bool match_vec_multiple(std::vector<int>& first, std::vector<std::vector<int>>& list) {
   for (unsigned i = 0; i < list.size(); i++) {
      unsigned num = 0;
      for (unsigned j = 0; j < first.size(); j++) {
         if (i < list[i].size() && first[j] == list[i][j]) {
            num++;
         }
      }
      if (num == list[i].size()) {
         return true;
      }
   }
   return false;;
}

TEST_CASE("Graph Insert Nodes Correctly", "[graph][insert]") {
   Graph graph;
   graph.insertVertex(1);
   graph.insertVertex(2);
   graph.insertVertex(3);
   graph.insertVertex(4);

   SECTION("Graph Insert Edges Correctly") {
      graph.insertEdge(3, 4, 1);
      graph.insertEdge(1, 2, 1);
      REQUIRE(graph.getEdgeList().size() == 2);
      //verify edges
      REQUIRE(graph.areAdjacent(3, 4));
      REQUIRE(graph.areAdjacent(1, 2));
      //verify non-edges
      REQUIRE(!graph.areAdjacent(1, 3));
      REQUIRE(!graph.areAdjacent(2, 4));

   }
   REQUIRE(graph.getAdjList().size() == 4);
}

TEST_CASE("Graph Incident Edges", "[graph][incident]") {
   Graph graph;
   graph.insertVertex(1);
   graph.insertVertex(2);
   graph.insertVertex(3);
   graph.insertVertex(4);
   graph.insertVertex(5);
   graph.insertVertex(6);

   graph.insertEdge(3, 4, 1);
   graph.insertEdge(3, 5, 1);
   graph.insertEdge(3, 6, 1);

   //verify incident edge size
   REQUIRE(graph.incidentEdges(3).size() == 3);
   REQUIRE(graph.areAdjacent(3, 4));
   REQUIRE(graph.areAdjacent(3, 5));
   REQUIRE(graph.areAdjacent(3, 6));

   REQUIRE(!graph.areAdjacent(3, 1));
   REQUIRE(!graph.areAdjacent(3, 2));
   
}

TEST_CASE("NodeReader reads SNAP format", "[graph][reader]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);
   REQUIRE(graph.areAdjacent(1, 2));
   REQUIRE(graph.areAdjacent(1, 3));
   REQUIRE(graph.areAdjacent(1, 7));
   REQUIRE(graph.areAdjacent(1, 9));
   REQUIRE(graph.areAdjacent(1, 10));
   REQUIRE(graph.areAdjacent(1, 11));
   REQUIRE(graph.areAdjacent(1, 12));
   REQUIRE(graph.areAdjacent(2, 1));
   REQUIRE(graph.areAdjacent(2, 5));
   REQUIRE(graph.areAdjacent(2, 13));
   REQUIRE(graph.areAdjacent(3, 1));
   REQUIRE(graph.areAdjacent(3, 6));
   REQUIRE(graph.areAdjacent(3, 8));
   REQUIRE(graph.areAdjacent(4, 5));
   REQUIRE(graph.areAdjacent(4, 13));
   REQUIRE(graph.areAdjacent(4, 18));
   REQUIRE(graph.areAdjacent(5, 2));
   REQUIRE(graph.areAdjacent(5, 4));
   REQUIRE(graph.areAdjacent(5, 6));
   REQUIRE(graph.areAdjacent(5, 17));
   REQUIRE(graph.areAdjacent(6, 3));
   REQUIRE(graph.areAdjacent(6, 5));
   REQUIRE(graph.areAdjacent(7, 1));
   REQUIRE(graph.areAdjacent(7, 8));
   REQUIRE(graph.areAdjacent(7, 9));
   REQUIRE(graph.areAdjacent(8, 3));
   REQUIRE(graph.areAdjacent(8, 7));
   REQUIRE(graph.areAdjacent(8, 14));
   REQUIRE(graph.areAdjacent(8, 15));
   REQUIRE(graph.areAdjacent(9, 1));
   REQUIRE(graph.areAdjacent(9, 7));
   REQUIRE(graph.areAdjacent(9, 10));
   REQUIRE(graph.areAdjacent(9, 14));
   REQUIRE(graph.areAdjacent(10, 1));
   REQUIRE(graph.areAdjacent(10, 9));
   REQUIRE(graph.areAdjacent(10, 11));
   REQUIRE(graph.areAdjacent(11, 1));
   REQUIRE(graph.areAdjacent(11, 10));
   REQUIRE(graph.areAdjacent(11, 12));
   REQUIRE(graph.areAdjacent(12, 1));
   REQUIRE(graph.areAdjacent(12, 11));
   REQUIRE(graph.areAdjacent(12, 13));
   REQUIRE(graph.areAdjacent(13, 2));
   REQUIRE(graph.areAdjacent(13, 4));
   REQUIRE(graph.areAdjacent(13, 12));
   REQUIRE(graph.areAdjacent(13, 18));
   REQUIRE(graph.areAdjacent(14, 8));
   REQUIRE(graph.areAdjacent(14, 9));
   REQUIRE(graph.areAdjacent(15, 8));
   REQUIRE(graph.areAdjacent(15, 16));
   REQUIRE(graph.areAdjacent(16, 17));
   REQUIRE(graph.areAdjacent(17, 5));
   REQUIRE(graph.areAdjacent(17, 16));
   REQUIRE(graph.areAdjacent(17, 18));
   REQUIRE(graph.areAdjacent(18, 4));
   REQUIRE(graph.areAdjacent(18, 13));
   REQUIRE(graph.areAdjacent(18, 17));

   REQUIRE(graph.getEdgeList().size() == 29);
}

TEST_CASE("Graph BFS Correctness", "[graph][BFS]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);

   SECTION("BFS Path 1") {
      std::vector<int> ans_path = graph.BFS(5, 14);
      std::vector<int> correct = {5, 6, 3, 8, 14};
      REQUIRE(match_vec(ans_path, correct));
   }
   SECTION("BFS Path 2") {
      std::vector<int> ans_path = graph.BFS(10, 16);
      std::vector<std::vector<int>> choices = 
      {  {10, 1, 2, 5, 17, 16}, 
         {10, 1, 3, 8, 15, 16}, 
         {10, 9, 14, 8, 15, 16}  };
      REQUIRE(match_vec_multiple(ans_path, choices));
   }
   SECTION("BFS Path 3") {
      std::vector<int> ans_path = graph.BFS(12, 17);
      std::vector<int> correct = {12, 13, 18, 17};
      REQUIRE(match_vec(ans_path, correct));
   }

}

TEST_CASE("Graph Connected Subgraph", "[graph][BFS]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);
   Graph subgraph = graph.connected_subgraph(1, 7);
   REQUIRE(subgraph.getAdjList().size() == 7);
}

TEST_CASE("Graph Betweenness Centrality", "[graph][BC]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);
   Graph subgraph = graph.connected_subgraph(1, 7);

   std::vector<std::pair<int, float>> BC = graph.betweenness_centrality(5);
   
   REQUIRE(BC[0].first == 1);
   REQUIRE(BC[1].first == 8);
   REQUIRE(BC[2].first == 5);
}


TEST_CASE("Graph Draw", "[graph][draw]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);

   graph.betweenness_centrality(1);
   REQUIRE_NOTHROW(graph.draw_graph("", 1000, 1000, true));
   
}

TEST_CASE("Reads In Full Data", "[.][full]") {
   Graph graph;
   NodeReader reader("225FPDataset/com-amazon-reduced.ungraph.txt");
   reader.readInEdgeList(graph);
   reader.readInLabels("225FPDataset/amazon-meta-reduced.txt");

   REQUIRE(graph.getAdjList().size() == 334863 - 11);

   SECTION("Verify Data Cleaned", "[full][clean]") {
      auto hash = graph.getAdjList();
      for (auto &pair : hash ) {
         REQUIRE(reader.getLabels().find(pair.first) != reader.getLabels().end());
         REQUIRE(reader[pair.first] != "discontinued product");
      }
      REQUIRE(graph.areAdjacent(548096, 548099));
      REQUIRE(!graph.areAdjacent(548096, 548406));
   }

   SECTION("Betweenness Centrality on Sub-Graph", "[full][BC]") {
      Graph subgraph = graph.connected_subgraph(100000, 300);

      std::vector<std::pair<int, float>> BC = subgraph.betweenness_centrality(5);
      
      REQUIRE(BC[0].first == 370312);
      REQUIRE(BC[1].first == 506956);
      REQUIRE(BC[2].first == 364286);
      REQUIRE(subgraph.getAdjList().size() == 300);
      REQUIRE(BC.size() == 5);
   }
   
   SECTION("Dataset subset Graph Draw", "[full][draw]") {
      Graph subgraph = graph.connected_subgraph(100000, 750);
      std::vector<std::pair<int, float>> BC = subgraph.betweenness_centrality(5);
      REQUIRE_NOTHROW(subgraph.draw_graph("", 1000, 1000, true));
   }

   SECTION("BFS on Graph", "[full][BFS]") {
      std::vector<int> path = graph.BFS(1, 404753);
      std::vector<int> correct = {1, 346495, 143523, 282951, 246278, 211432, 24849, 205174, 516401, 166838, 329844, 81706, 455139, 450413, 404753};
      REQUIRE(match_vec(path, correct));
   }
}

