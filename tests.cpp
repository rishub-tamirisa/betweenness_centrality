#include "catch.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "fmi.h"

/*
* Helper functions for basic tests
*/


void matchString(std::string output, std::string ans){

  REQUIRE(output.size() == ans.size());

  for(size_t i = 0; i < ans.size(); ++i){
    if(output[i]!=ans[i]){ 
      INFO("At index value: " + std::to_string(i) + " your string was incorrect.");
      REQUIRE(output[i] == ans[i]);
    }
  }
}

void matchSarray(std::vector<int> output, std::vector<int> ans){

  REQUIRE(output.size() == ans.size());

  for(size_t i = 0; i < ans.size(); ++i){
    if(output[i]!=ans[i]){ 
      INFO("At index value: " + std::to_string(i) + " your array was incorrect.");
      REQUIRE(output[i] == ans[i]);
    }
  }
}

void matchSortArray(std::vector<int> output, std::vector<int> ans){
  std::sort(output.begin(),output.end()); 
  std::sort(ans.begin(),ans.end()); 

  REQUIRE(output.size() == ans.size());

  for(size_t i = 0; i < ans.size(); ++i){
    if(output[i]!=ans[i]){ 
      INFO("At index value: " + std::to_string(i) + " your array (when sorted) was incorrect.");
      REQUIRE(output[i] == ans[i]);
    }
  }
}

void match_2D_Array(std::vector<std::vector<int>> output, std::vector<std::vector<int>> ans){
  REQUIRE(output.size() == ans.size());

  for(int i = 0; i < (int) ans.size(); ++i){
    REQUIRE(output[i].size() == ans[i].size());

    for(int j = 0; j < (int) ans[i].size(); ++j){
      if(output[i][j]!=ans[i][j]){ 
        INFO("At vector[" + std::to_string(i) + "]["+ std::to_string(j) +"] your value was incorrect.");
        REQUIRE(output[i][j] == ans[i][j]);
      }
    }
  }
}

/*
* Public test cases for FMI construction (Total 20 points)
*/

TEST_CASE("FM Index BWT Public Test", "[weight=5]") {
  std::string alpha = "AB";
  std::string T = "BABAAAB";
  std::string ans = "BBAABAA$";

  FMI myFM = FMI(T, alpha);

  matchString(myFM.BWT,ans);

  alpha = "ABCDEFG";
  T = "ABCDEFG";
  ans = "G$ABCDEF";

  myFM = FMI(T, alpha);
  matchString(myFM.BWT,ans);

  T = "BBABBABABBA";
  ans = "ABBBBBBABAA$";

  myFM = FMI(T, alpha);
  matchString(myFM.BWT,ans);
}

TEST_CASE("FM Index SA Public Test", "[weight=5]") {
  std::string alpha = "AB";
  std::string T = "BABAAAB";
  std::vector<int> ans = { 7, 3, 4, 5, 1, 6, 2, 0};

  FMI myFM = FMI(T, alpha);

  matchSarray(myFM.SA,ans);

  alpha = "ABCDEFG";
  T = "ABCDEFG";
  ans = { 7, 0, 1, 2, 3, 4, 5, 6};

  myFM = FMI(T, alpha);
  matchSarray(myFM.SA,ans);

  T = "BBABBABABBA";
  ans = { 11, 10, 5, 7, 2, 9, 4, 6, 1, 8, 3, 0};

  myFM = FMI(T, alpha);
  matchSarray(myFM.SA,ans);
}

TEST_CASE("FM Index OT Public Test 1", "[weight=5]") {
  std::string alpha = "AB";
  std::string T = "BABAAAB";
  std::vector<std::vector<int>> ans = { { 0, 1}, \
{ 0, 2}, \
{ 1, 2}, \
{ 2, 2}, \
{ 2, 3}, \
{ 3, 3}, \
{ 4, 3}, \
{ 4, 3} };

  FMI myFM = FMI(T, alpha);

  match_2D_Array(myFM.OT,ans);

  alpha = "ABCDEFG";
  T = "ABCDEFG";
  ans = { { 0, 0, 0, 0, 0, 0, 1}, \
{ 0, 0, 0, 0, 0, 0, 1}, \
{ 1, 0, 0, 0, 0, 0, 1}, \
{ 1, 1, 0, 0, 0, 0, 1}, \
{ 1, 1, 1, 0, 0, 0, 1}, \
{ 1, 1, 1, 1, 0, 0, 1}, \
{ 1, 1, 1, 1, 1, 0, 1}, \
{ 1, 1, 1, 1, 1, 1, 1} };

  myFM = FMI(T, alpha);
  match_2D_Array(myFM.OT,ans);

  T = "BBABBABABBA";
  ans = { { 1, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 0, 0, 0, 0, 0}, \
{ 1, 2, 0, 0, 0, 0, 0}, \
{ 1, 3, 0, 0, 0, 0, 0}, \
{ 1, 4, 0, 0, 0, 0, 0}, \
{ 1, 5, 0, 0, 0, 0, 0}, \
{ 1, 6, 0, 0, 0, 0, 0}, \
{ 2, 6, 0, 0, 0, 0, 0}, \
{ 2, 7, 0, 0, 0, 0, 0}, \
{ 3, 7, 0, 0, 0, 0, 0}, \
{ 4, 7, 0, 0, 0, 0, 0}, \
{ 4, 7, 0, 0, 0, 0, 0} };

  myFM = FMI(T, alpha);
  match_2D_Array(myFM.OT,ans);
}

TEST_CASE("FM Index OT Public Test 2", "[weight=5]") {
  std::string alpha = "abcdefghijklmnopqrstuvwxyz_";
  std::string T = "beep_beep_ima_sheep";
  std::vector<std::vector<int>> ans = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 2, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 1, 1, 2, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 2, 1, 2, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 2, 1, 2, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 2, 1, 2, 0, 0, 4, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 2, 1, 2, 0, 0, 5, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 2, 1, 2, 0, 0, 6, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, \
{ 3, 1, 2, 0, 0, 6, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0} };
  FMI myFM = FMI(T, alpha);

  match_2D_Array(myFM.OT,ans);

  alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_";
  T = "Phnglui_mglwnafh_Cthulhu_Rlyeh_wgahnagl_fhtagn";
  ans = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 1, 1, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 1, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 1, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 1, 2, 1, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 1, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 2, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 2, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 3, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 4, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 1, 2, 4, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 4, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 1, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 2, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 3, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 4, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 5, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 5, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 6, 1, 0, 0, 2, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 6, 1, 0, 0, 3, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 2, 5, 7, 1, 0, 0, 3, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 1, 2, 5, 7, 1, 0, 0, 3, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 1, 2, 5, 7, 1, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0}, \
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 1, 2, 5, 7, 1, 0, 0, 5, 1, 4, 0, 0, 0, 0, 0, 2, 3, 0, 2, 0, 1, 0} };

  myFM = FMI(T, alpha);
  match_2D_Array(myFM.OT,ans);
}


/*
* Public test cases for FMI F Range Function (Total 10 points)
*/
TEST_CASE("FM Index get_frange Public Test 1", "[weight=5]") {
  std::string T = "DACCABBACCA";
  std::string alpha = "ABCD";
  std::vector<int> ans;

  FMI myFM = FMI(T, alpha);

  std::pair<int, int> op = myFM.get_frange("B",0,1);
  std::vector<int> out = {op.first, op.second};
  ans = {5, 6};

  matchSarray(out,ans);

  op = myFM.get_frange("B", 1, 1);
  out = {op.first, op.second};
  ans = {6, 6};

  matchSarray(out,ans);

  op = myFM.get_frange("D", 0, 0);
  out = {op.first, op.second};
  ans = {11, 11};

  matchSarray(out,ans);

  op = myFM.get_frange("C", 0, 3);
  out = {op.first, op.second};
  ans = {7, 10};

  matchSarray(out,ans);
}

TEST_CASE("FM Index get_frange Public Test 2", "[weight=5]") {
  std::string T = "BABAAAB";
  std::string alpha = "AB";
  std::vector<int> ans;

  FMI myFM = FMI(T, alpha);

  std::pair<int, int> op = myFM.get_frange("A",0,3);
  std::vector<int> out = {op.first, op.second};
  ans = {1, 4};

  matchSarray(out,ans);

  op = myFM.get_frange("A", 0, 1);
  out = {op.first, op.second};
  ans = {1, 2};

  matchSarray(out,ans);

  op = myFM.get_frange("B", 0, 1);
  out = {op.first, op.second};
  ans = {5, 6};

  matchSarray(out,ans);

  op = myFM.get_frange("B", 0, 2);
  out = {op.first, op.second};
  ans = {5, 7};

  matchSarray(out,ans);
}
/*
* Public test cases for FMI L Range Function (Total 10 points)
*/

TEST_CASE("FM Index get_lrange Public Test 1", "[weight=5]") {
  std::string T = "DACCABBACCA";
  std::string P = "ABB";
  std::string alpha = "ABCD";
  std::vector<int> ans;

  FMI myFM = FMI(T, alpha);

  std::pair<int, int> op = myFM.get_lrange("B", 5, 6);
  std::vector<int> out = {op.first, op.second};
  ans = {1, 2};

  matchSarray(out,ans);

  op = myFM.get_lrange("A", 6, 6);
  out = {op.first, op.second};
  ans = {1, 2};

  matchSarray(out,ans);

  op = myFM.get_lrange("D", 1, 1);
  out = {op.first, op.second};
  ans = {0, 0};

  matchSarray(out,ans);

  op = myFM.get_lrange("C", 1, 3);
  out = {op.first, op.second};
  ans = {0, 2};

  matchSarray(out,ans);
}

TEST_CASE("FM Index get_lrange Public Test 2", "[weight=5]") {
  std::string T = "BABAAAB";
  std::string alpha = "AB";
  std::vector<int> ans;

  FMI myFM = FMI(T, alpha);

  std::pair<int, int> op = myFM.get_lrange("A", 1, 4);
  std::vector<int> out = {op.first, op.second};
  ans = {0, 2};

  matchSarray(out,ans);

  op = myFM.get_lrange("A", 1, 1);
  out = {op.first, op.second};
  ans = {0, 0};

  matchSarray(out,ans);

  op = myFM.get_lrange("B", 1, 1);
  out = {op.first, op.second};
  ans = {1, 2};

  matchSarray(out,ans);

  op = myFM.get_lrange("B", 1, 3);
  out = {op.first, op.second};
  ans = {1, 2};

  matchSarray(out,ans);
}

/*
* Public test cases for FMI Search (Total 10 points)
*/
TEST_CASE("FM Index Search Public Test 1", "[weight=5]") {
  std::string alpha = "AB";
  std::string T = "BABAAAB";
  std::string P = "AA";
  std::vector<int> ans = { 3, 4};

  FMI myFM = FMI(T, alpha);
  std::vector<int> out = myFM.search(P);

  // matchSortArray(out,ans);

  alpha = "ABCD";
  T = "BBABBABABBA";
  P = "ABB";
  ans = { 7, 2};

  myFM = FMI(T, alpha);
  out = myFM.search(P);

  matchSortArray(out,ans);
}

TEST_CASE("FM Index Search Public Test 2", "[weight=5]") {
  std::string alpha = "ABCDEFG";
  std::string T = "DACCABBACCA";
  std::string P = "A";
  std::vector<int> ans = { 10, 4, 7, 1 };

  FMI myFM = FMI(T, alpha);
  std::vector<int> out = myFM.search(P);

  matchSortArray(out,ans);

  P = "E";
  ans = { -1 };

  out = myFM.search(P);

  matchSortArray(out,ans);

  P = "ADD";
  ans = { -1 };

  out = myFM.search(P);

  matchSortArray(out,ans);

  P = "ABB";
  ans = { 4 };

  out = myFM.search(P);

  matchSortArray(out,ans);
}