//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <vector>
#include <core/graph.h>
#include <core/bfs.h>
#include <core/dfs.h>

using std::vector;
using graph_algorithm::Graph;
using graph_algorithm::BFS;
using graph_algorithm::DFS;

TEST_CASE("Testing the BFS and DFS class") {
  SECTION("Testing the RunBFS and RunDFS function for a 4x4 board") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1}};

    vector<vector<int>> bfs_output = {{2, 2, 2, 2},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.RunBFS(3, 0) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.RunDFS(3, 0) == dfs_output);
  }

  SECTION("Testing the RunBFS and RunDFS function for a 5x5 board") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1}};

    vector<vector<int>> bfs_output = {{2, 2, 2, 2, 2},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2, 2},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.RunBFS(0, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.RunDFS(0, 4) == dfs_output);
  }

  SECTION("Testing the RunBFS and RunDFS function for a valid path for a board"
          "with one possible path") {
    vector<vector<int>> board = {{0, 1, 1, 1, 1},
                                 {1, 0, 1, 1, 1},
                                 {1, 1, 0, 1, 1},
                                 {1, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 0}};

    vector<vector<int>> bfs_output = {{2, 1, 1, 1, 1},
                                      {1, 2, 1, 1, 1},
                                      {1, 1, 2, 1, 1},
                                      {1, 1, 1, 2, 1},
                                      {1, 1, 1, 1, 2}};

    vector<vector<int>> dfs_output = {{2, 1, 1, 1, 1},
                                      {1, 2, 1, 1, 1},
                                      {1, 1, 2, 1, 1},
                                      {1, 1, 1, 2, 1},
                                      {1, 1, 1, 1, 2}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.RunBFS(4, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.RunDFS(4, 4) == dfs_output);
  }
}