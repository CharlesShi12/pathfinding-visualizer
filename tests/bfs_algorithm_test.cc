//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <vector>
#include <core/graph.h>
#include <core/bfs.h>

using std::vector;
using graph_algorithm::Graph;
using graph_algorithm::BFS;

TEST_CASE("Testing the BFS class") {
  SECTION("Testing the RunBFS function for a 4x4 board") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1}};

    vector<vector<int>> output = {{2, 2, 2, 2},
                                  {2, 1, 1, 1},
                                  {2, 1, 1, 1},
                                  {2, 1, 1, 1}};

    auto *board_graph = new Graph(board);
    BFS *bfs_algorithm = new BFS(board_graph);

    REQUIRE(bfs_algorithm->RunBFS(3, 0) == output);
  }

  SECTION("Testing the RunBFS function for a 5x5 board") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1}};

    vector<vector<int>> output = {{2, 2, 2, 2, 2},
                                  {2, 1, 1, 1, 1},
                                  {2, 1, 1, 1, 1},
                                  {2, 1, 1, 1, 1},
                                  {0, 1, 1, 1, 1}};

    auto *board_graph = new Graph(board);
    BFS *bfs_algorithm = new BFS(board_graph);

    REQUIRE(bfs_algorithm->RunBFS(0, 4) == output);
  }
}

