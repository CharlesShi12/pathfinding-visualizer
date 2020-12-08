//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <vector>
#include <core/graph.h>
#include <core/bfs.h>
#include <core/dfs.h>
#include <core/bidirectional_bfs.h>
#include <core/a_star.h>
#include <core/pathfinder.h>

using std::vector;
using graph_algorithm::Graph;
using graph_algorithm::BFS;
using graph_algorithm::DFS;
using graph_algorithm::BidirectionalBFS;
using graph_algorithm::AStar;
using graph_algorithm::Pathfinder;

TEST_CASE("Testing the BFS, BidirectionalBFS, AStar, and DFS class") {
  SECTION("Testing the Find function for a 4x4 board with no walls") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2},
                                                      {4, 2, 2, 2},
                                                      {4, 2, 2, 2},
                                                      {4, 4, 4, 4}},

                                                     {{4, 0, 0, 0},
                                                      {4, 0, 0, 0},
                                                      {4, 0, 0, 0},
                                                      {4, 4, 4, 4}},

                                                     {{4, 2, 2, 0},
                                                      {4, 2, 0, 5},
                                                      {4, 6, 5, 5},
                                                      {2, 4, 4, 4}},

                                                     {{4, 4, 2, 2},
                                                      {2, 4, 4, 2},
                                                      {2, 2, 4, 4},
                                                      {2, 2, 2, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(3, 3) == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 5x5 board with no walls") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2, 2},
                                                      {4, 2, 2, 2, 2},
                                                      {4, 2, 2, 2, 2},
                                                      {4, 2, 2, 2, 2},
                                                      {4, 4, 4, 4, 4}},

                                                     {{4, 0, 0, 0, 0},
                                                      {4, 0, 0, 0, 0},
                                                      {4, 0, 0, 0, 0},
                                                      {4, 0, 0, 0, 0},
                                                      {4, 4, 4, 4, 4}},

                                                     {{4, 2, 2, 2, 0},
                                                      {4, 2, 2, 0, 5},
                                                      {4, 2, 0, 5, 5},
                                                      {4, 6, 5, 5, 5},
                                                      {2, 4, 4, 4, 4}},

                                                     {{4, 4, 2, 2, 2},
                                                      {2, 4, 4, 2, 2},
                                                      {2, 2, 4, 4, 2},
                                                      {2, 2, 2, 4, 4},
                                                      {2, 2, 2, 2, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(4, 4) == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 4x4 board with walls") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 0},
                                 {0, 1, 1, 0},
                                 {0, 0, 0, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2},
                                                      {4, 1, 1, 2},
                                                      {4, 1, 1, 2},
                                                      {4, 4, 4, 4}},

                                                     {{4, 0, 0, 0},
                                                      {4, 1, 1, 0},
                                                      {4, 1, 1, 0},
                                                      {4, 4, 4, 4}},

                                                     {{4, 2, 2, 0},
                                                      {4, 1, 1, 5},
                                                      {4, 1, 1, 5},
                                                      {6, 4, 4, 4}},

                                                     {{4, 4, 4, 4},
                                                      {2, 1, 1, 4},
                                                      {2, 1, 1, 4},
                                                      {2, 2, 2, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(3, 3) == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 5x5 board with walls") {
    vector<vector<int>> board = {{0, 1, 1, 1, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 4, 4, 4, 4}},

                                                     {{4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 4, 4, 4, 4}},

                                                     {{4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 5},
                                                      {4, 1, 1, 1, 5},
                                                      {4, 1, 1, 1, 5},
                                                      {4, 6, 4, 4, 4}},

                                                     {{4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 1, 1, 1, 0},
                                                      {4, 4, 4, 4, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(4, 4) == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 4x4 board with walls and an"
          "unreachable node") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {1, 1, 1, 0},
                                 {1, 0, 1, 0},
                                 {1, 1, 1, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 4, 4, 4},
                                                      {1, 1, 1, 4},
                                                      {1, 0, 1, 4},
                                                      {1, 1, 1, 4}},

                                                     {{4, 4, 4, 4},
                                                      {1, 1, 1, 4},
                                                      {1, 0, 1, 4},
                                                      {1, 1, 1, 4}},

                                                     {{4, 4, 4, 6},
                                                      {1, 1, 1, 4},
                                                      {1, 0, 1, 4},
                                                      {1, 1, 1, 4}},

                                                     {{4, 4, 4, 4},
                                                      {1, 1, 1, 4},
                                                      {1, 0, 1, 4},
                                                      {1, 1, 1, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(3, 3) == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 5x5 with walls and unreachable"
          "nodes") {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {1, 1, 1, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 1, 0, 0}};
    Graph board_graph(board);

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new DFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2, 2},
                                                      {4, 4, 4, 4, 2},
                                                      {1, 1, 1, 4, 2},
                                                      {0, 0, 1, 4, 0},
                                                      {0, 0, 1, 0, 0}},

                                                     {{4, 0, 0, 0, 0},
                                                      {4, 4, 4, 4, 0},
                                                      {1, 1, 1, 4, 0},
                                                      {0, 0, 1, 4, 0},
                                                      {0, 0, 1, 0, 0}},

                                                     {{4, 2, 2, 2, 0},
                                                      {4, 4, 4, 6, 5},
                                                      {1, 1, 1, 4, 5},
                                                      {0, 0, 1, 4, 5},
                                                      {0, 0, 1, 5, 5}},

                                                     {{4, 4, 2, 2, 0},
                                                      {2, 4, 4, 4, 0},
                                                      {1, 1, 1, 4, 0},
                                                      {0, 0, 1, 4, 0},
                                                      {0, 0, 1, 0, 0}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      REQUIRE(pathfinder[i]->Find(3, 3) == pathfinder_output[i]);
    }
  }
}

TEST_CASE("Testing the BFS, BidirectionalBFS, AStar class for shortest path") {
  SECTION("Testing the Find function for a 5x5 board") {

  }

  SECTION("Testing the Find function for a 6x6 board") {

  }
}