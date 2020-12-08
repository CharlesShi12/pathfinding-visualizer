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
#include <visualizer/sketchpad.h>

using graph_algorithm::Graph;
using graph_algorithm::BFS;
using graph_algorithm::DFS;
using graph_algorithm::BidirectionalBFS;
using graph_algorithm::AStar;
using graph_algorithm::Pathfinder;
using std::vector;

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
  SECTION("Testing the Find function for a 4x4 board") {
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 1, 1, 0},
                                 {0, 0, 0, 0},
                                 {1, 1, 1, 0}};
    Graph board_graph(board);
    size_t dimension = board_graph.GetDimension();

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2},
                                                      {4, 1, 1, 2},
                                                      {4, 4, 4, 4},
                                                      {1, 1, 1, 4}},

                                                     {{4, 2, 2, 5},
                                                      {4, 1, 1, 5},
                                                      {4, 6, 4, 4},
                                                      {1, 1, 1, 4}},

                                                     {{4, 2, 2, 2},
                                                      {4, 1, 1, 2},
                                                      {4, 4, 4, 4},
                                                      {1, 1, 1, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      size_t shortest_path_length = 0;
      vector<vector<int>> new_board = pathfinder[i]->Find(3, 3);

      // make sure that our algorithm's path is the shortest possible path
      for (size_t row = 0; row < dimension; row++) {
        for (size_t col = 0; col < dimension; col++) {
          if (new_board[row][col] == graph_algorithm::kPath ||
              new_board[row][col] == graph_algorithm::kIntersectionNode) {
            shortest_path_length++;
          }
        }
      }

      REQUIRE(shortest_path_length == 7);
      REQUIRE(new_board == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 5x5 board") {
    vector<vector<int>> board = {{0, 0, 0, 0, 1},
                                 {0, 1, 1, 0, 0},
                                 {0, 0, 1, 0, 1},
                                 {0, 0, 0, 0, 0},
                                 {1, 1, 0, 0, 0}};
    Graph board_graph(board);
    size_t dimension = board_graph.GetDimension();

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2, 1},
                                                      {4, 1, 1, 2, 2},
                                                      {4, 2, 1, 2, 1},
                                                      {4, 4, 4, 2, 2},
                                                      {1, 1, 4, 4, 4}},

                                                     {{4, 2, 2, 2, 1},
                                                      {4, 1, 1, 0, 0},
                                                      {4, 2, 1, 5, 1},
                                                      {4, 6, 4, 5, 5},
                                                      {1, 1, 4, 4, 4}},

                                                     {{4, 4, 4, 4, 1},
                                                      {2, 1, 1, 4, 2},
                                                      {2, 2, 1, 4, 1},
                                                      {2, 2, 2, 4, 4},
                                                      {1, 1, 2, 2, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      size_t shortest_path_length = 0;
      vector<vector<int>> new_board = pathfinder[i]->Find(4, 4);

      // make sure that our algorithm's path is the shortest possible path
      for (size_t row = 0; row < dimension; row++) {
        for (size_t col = 0; col < dimension; col++) {
          if (new_board[row][col] == graph_algorithm::kPath ||
              new_board[row][col] == graph_algorithm::kIntersectionNode) {
            shortest_path_length++;
          }
        }
      }

      REQUIRE(shortest_path_length == 9);
      REQUIRE(new_board == pathfinder_output[i]);
    }
  }

  SECTION("Testing the Find function for a 6x6 board") {
    vector<vector<int>> board = {{0, 0, 0, 0, 1, 0},
                                 {0, 0, 1, 0, 0, 1},
                                 {1, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {1, 0, 1, 1, 1, 0}};
    Graph board_graph(board);
    size_t dimension = board_graph.GetDimension();

    vector<Pathfinder *> pathfinder = {new BFS(&board_graph),
                                       new BidirectionalBFS(&board_graph),
                                       new AStar(&board_graph)};

    vector<vector<vector<int>>> pathfinder_output = {{{4, 2, 2, 2, 1, 0},
                                                      {4, 4, 1, 2, 2, 1},
                                                      {1, 4, 1, 2, 2, 2},
                                                      {2, 4, 2, 1, 2, 2},
                                                      {2, 4, 4, 4, 4, 4},
                                                      {1, 2, 1, 1, 1, 4}},

                                                     {{4, 2, 2, 2, 1, 0},
                                                      {4, 4, 1, 2, 0, 1},
                                                      {1, 4, 1, 0, 5, 5},
                                                      {2, 4, 6, 1, 5, 5},
                                                      {0, 2, 4, 4, 4, 4},
                                                      {1, 0, 1, 1, 1, 4}},

                                                     {{4, 4, 4, 4, 1, 0},
                                                      {2, 2, 1, 4, 2, 1},
                                                      {1, 2, 1, 4, 4, 2},
                                                      {0, 2, 2, 1, 4, 2},
                                                      {0, 2, 2, 2, 4, 4},
                                                      {1, 2, 1, 1, 1, 4}}};

    for (size_t i = 0; i < pathfinder.size(); i++) {
      size_t shortest_path_length = 0;
      vector<vector<int>> new_board = pathfinder[i]->Find(5, 5);

      // make sure that our algorithm's path is the shortest possible path
      for (size_t row = 0; row < dimension; row++) {
        for (size_t col = 0; col < dimension; col++) {
          if (new_board[row][col] == graph_algorithm::kPath ||
              new_board[row][col] == graph_algorithm::kIntersectionNode) {
            shortest_path_length++;
          }
        }
      }

      REQUIRE(shortest_path_length == 11);
      REQUIRE(new_board == pathfinder_output[i]);
    }
  }
}