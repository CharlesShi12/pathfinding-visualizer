//
// Created by Charles Shi on 12/7/20.
//

#include <catch2/catch.hpp>
#include <visualizer/sketchpad.h>
#include <vector>

using graph_algorithm::visualizer::Sketchpad;
using std::vector;
using std::pair;

TEST_CASE("Testing the Sketchpad class") {
  // put random values for the sketchpad constructor; won't affect the testing
  Sketchpad sketchpad(glm::vec2(10, 10), 10, 10);

  SECTION("Testing the CountPathAndTraversedNodes function for a 4x4 board with"
          "empty nodes (represented as 0), walls (1), traversed nodes (2),"
          "start and end nodes (3), and final path (4)") {
    vector<vector<int>> board = {{1, 2, 0, 0},
                                 {1, 0, 3, 3},
                                 {2, 3, 4, 0},
                                 {0, 0, 4, 2}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 2);
    REQUIRE(output.second == 5);
  }

  SECTION("Testing the CountPathAndTraversedNodes function for a 5x5 board with"
          "empty nodes (represented as 0), walls (1), traversed nodes (2),"
          "start and end nodes (3), and final path (4)") {
    vector<vector<int>> board = {{1, 2, 0, 0, 0},
                                 {1, 0, 3, 3, 2},
                                 {2, 3, 4, 0, 4},
                                 {0, 0, 4, 2, 1},
                                 {1, 2, 3, 4, 0}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 4);
    REQUIRE(output.second == 9);
  }

  SECTION("Testing the CountPathAndTraversedNodes function for a 4x4 board with"
          "empty nodes (represented as 0), final path (4), alternative"
          "traversed nodes (5), and intersection node (6)") {
    vector<vector<int>> board = {{4, 5, 6, 4},
                                 {4, 0, 5, 4},
                                 {5, 6, 4, 0},
                                 {0, 0, 6, 6}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 9);
    REQUIRE(output.second == 12);
  }

  SECTION("Testing the CountPathAndTraversedNodes function for a 5x5 board with"
          "empty nodes (represented as 0), final path (4), alternative"
          "traversed nodes (5), and intersection node (6)") {
    vector<vector<int>> board = {{4, 4, 0, 6, 0},
                                 {5, 0, 5, 4, 5},
                                 {6, 4, 6, 0, 4},
                                 {0, 0, 4, 6, 5},
                                 {5, 5, 6, 4, 4}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 13);
    REQUIRE(output.second == 19);
  }

  SECTION("Testing the CountPathAndTraversedNodes function for a 4x4 board with"
          "empty nodes (represented as 0), walls (1), traversed nodes (2),"
          "start and end nodes (3), final path (4), alternative"
          "traversed nodes (5), and intersection node (6)") {
    vector<vector<int>> board = {{1, 4, 0, 6},
                                 {5, 2, 3, 2},
                                 {6, 4, 2, 0},
                                 {0, 5, 4, 6}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 6);
    REQUIRE(output.second == 11);
  }

  SECTION("Testing the CountPathAndTraversedNodes function for a 5x5 board with"
          "empty nodes (represented as 0), walls (1), traversed nodes (2),"
          "start and end nodes (3), final path (4), alternative"
          "traversed nodes (5), and intersection node (6)") {
    vector<vector<int>> board = {{1, 4, 0, 6, 0},
                                 {5, 1, 3, 2, 5},
                                 {6, 4, 2, 0, 4},
                                 {0, 0, 4, 6, 5},
                                 {4, 5, 6, 3, 4}};
    sketchpad.SetCurrentBoard(board);

    pair<int, int> output = sketchpad.CountPathAndTraversedNodes();

    REQUIRE(output.first == 10);
    REQUIRE(output.second == 16);
  }
}