//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <vector>
#include <core/graph.h>
#include <core/dfs.h>

using std::vector;
using graph_algorithm::Graph;
using graph_algorithm::dfs::DFS;

TEST_CASE("Testing the DFS class") {
  SECTION("Testing the RunDFS function") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1},
                                 {0, 1, 1, 1}};

    vector<vector<int>> output = {{0, 2, 2, 2},
                                  {2, 1, 1, 1},
                                  {2, 1, 1, 1},
                                  {0, 1, 1, 1}};

    Graph *board_graph = new Graph(board);

    DFS *bfs_algorithm = new DFS(board_graph);

    REQUIRE(bfs_algorithm->RunDFS(3, 0) == output);
  }
}