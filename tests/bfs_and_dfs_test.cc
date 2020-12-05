//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <vector>
#include <core/graph.h>
#include <core/bfs.h>
#include <core/dfs.h>

//TODO: Ask if these tests are sufficient for BFS and DFS

using std::vector;
using graph_algorithm::Graph;
using graph_algorithm::BFS;
using graph_algorithm::DFS;

TEST_CASE("Testing the BFS and DFS class") {
  SECTION("Testing the Find function for a 4x4 board with multiple possible "
          "paths") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1}};

    // make sure that the start and end nodes are marked and also that the
    // final path traverses only the nodes that are reachable and not walls
    vector<vector<int>> bfs_output = {{4, 2, 2, 2},
                                      {4, 1, 1, 1},
                                      {4, 1, 1, 1},
                                      {4, 1, 1, 1}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1},
                                      {2, 1, 1, 1}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(3, 0) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(3, 0) == dfs_output);
  }

  SECTION("Testing the Find function for a 5x5 board with multiple possible "
          "paths") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1}};

    // make sure that the start and end nodes are marked and also that the
    // final path traverses only the nodes that are reachable and not walls
    vector<vector<int>> bfs_output = {{4, 4, 4, 4, 4},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2, 2},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 1}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(0, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(0, 4) == dfs_output);
  }

  SECTION("Testing the Find function for a board with one possible valid path "
          "and one node that is unreachable") {
    vector<vector<int>> board = {{0, 1, 1, 1, 0},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {0, 0, 0, 0, 0}};

    // the node at row 0 and column 4 should never be traversed in either one
    // of the DFS and BFS paths
    vector<vector<int>> bfs_output = {{4, 1, 1, 1, 0},
                                      {4, 1, 1, 1, 1},
                                      {4, 1, 1, 1, 1},
                                      {4, 1, 1, 1, 1},
                                      {4, 4, 4, 4, 4}};

    vector<vector<int>> dfs_output = {{2, 1, 1, 1, 0},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {2, 1, 1, 1, 1},
                                      {2, 2, 2, 2, 2}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(4, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(4, 4) == dfs_output);
  }

  SECTION("Testing the Find function for a board with multiple possible valid "
          "paths and one node that is unreachable") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 1, 0, 1, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0}};

    // the node at row 2 and column 2 should never be traversed in either one
    // of the DFS and BFS paths
    vector<vector<int>> bfs_output = {{4, 4, 4, 4, 4},
                                      {2, 1, 1, 1, 4},
                                      {2, 1, 0, 1, 4},
                                      {2, 1, 1, 1, 4},
                                      {2, 2, 2, 2, 4}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2, 2},
                                      {0, 1, 1, 1, 2},
                                      {0, 1, 0, 1, 2},
                                      {0, 1, 1, 1, 2},
                                      {0, 0, 0, 0, 2}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(4, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(4, 4) == dfs_output);
  }

  SECTION("Testing the Find function for a board with one possible valid path "
          "and multiple nodes that are unreachable") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0},
                                 {1, 0, 0, 1, 0},
                                 {1, 0, 0, 1, 0},
                                 {1, 1, 1, 1, 0}};

    vector<vector<int>> bfs_output = {{4, 4, 4, 4, 4},
                                      {1, 1, 1, 1, 4},
                                      {1, 0, 0, 1, 4},
                                      {1, 0, 0, 1, 4},
                                      {1, 1, 1, 1, 4}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2, 2},
                                      {1, 1, 1, 1, 2},
                                      {1, 0, 0, 1, 2},
                                      {1, 0, 0, 1, 2},
                                      {1, 1, 1, 1, 2}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(4, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(4, 4) == dfs_output);
  }

  SECTION("Testing the Find function for a board with multiple possible valid "
          "paths and multiple nodes that are unreachable") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {1, 1, 1, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 1, 0, 0}};

    vector<vector<int>> bfs_output = {{4, 4, 4, 4, 4},
                                      {2, 2, 2, 2, 4},
                                      {1, 1, 1, 2, 4},
                                      {0, 0, 1, 2, 4},
                                      {0, 0, 1, 2, 4}};

    vector<vector<int>> dfs_output = {{2, 2, 2, 2, 2},
                                      {2, 2, 2, 2, 2},
                                      {1, 1, 1, 2, 2},
                                      {0, 0, 1, 2, 2},
                                      {0, 0, 1, 2, 2}};

    Graph board_graph(board);

    BFS bfs_algorithm(&board_graph);
    REQUIRE(bfs_algorithm.Find(4, 4) == bfs_output);

    DFS dfs_algorithm(&board_graph);
    REQUIRE(dfs_algorithm.Find(4, 4) == dfs_output);
  }
}