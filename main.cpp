/**
 * @file main.cpp
 * A simple C++ program for building and searching an FM Index
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "fmi.h"

int main() {


  std::cout << "example 1" << std::endl;

  std::string T = "ABBBBA";
  std::string P = "BAA";
  std::string a = "AB";

  T="BBBAAA";
  P="ABA";
  a="AB";

  FMI myI = FMI(T, a);
  
  
  std::cout << "BWT:" << std::endl;

  std::cout << myI.BWT << std::endl;


  std::vector<std::vector<int>> OT = myI.OT;

  std::cout << "OT:" << std::endl;

  std::cout << "{ ";
  for (int i = 0; i < (int) OT.size(); ++i){
    std::cout << "{ ";
    for(int j = 0; j < (int) OT[i].size()-1; ++j){
      std::cout << OT[i][j] << ", ";
    }
    std::cout << OT[i][OT[i].size()-1] << "}, \\" << std::endl;
  }
  std::cout << "}" << std::endl;

  std::cout << "Suffix Array:" << std::endl;

  std::vector<int> SA = myI.SA;

  std::cout << "{ ";
  for(size_t i = 0; i < SA.size(); ++i){
    std::cout  << SA[i] << ", ";
  }
  std::cout << "}" << std::endl;

  std::cout << "Search Output: " << std::endl;

  std::vector<int> out = myI.search(P);

  std::cout << "{ ";
  for(size_t i = 0; i < out.size(); ++i){
    std::cout  << out[i] << ", ";
  }
  std::cout << "}" << std::endl;
  
  return 0;
}
