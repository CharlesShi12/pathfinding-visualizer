//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <core/graph.h>
#include <vector>

using graph_algorithm::Graph;
using std::vector;

TEST_CASE("Testing the Graph class") {
  SECTION("Testing the Constructor with a 2x2 board with no walls") {
    vector<vector<int>> board = {{0, 0},
                                 {0, 0}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();
    vector<Graph::Node *> nodes = board_graph->GetNodes();

    vector<vector<int>> adjacent = {{2, 1}, {3, 0}, {3, 0}, {2, 1}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(nodes[i]->row == (i / dimension));
      REQUIRE(nodes[i]->col == (i % dimension));
      REQUIRE(nodes[i]->distance == INFINITY);
      REQUIRE(nodes[i]->adjacent == adjacent[i]);
    }
  }

  SECTION("Testing the Constructor with a 3x3 board with no walls") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();
    vector<Graph::Node *> nodes = board_graph->GetNodes();

    vector<vector<int>> adjacent = {{3, 1}, {4, 2, 0}, {5, 1}, {6, 4, 0},
                                    {7, 5, 3, 1}, {8, 4, 2}, {7, 3}, {8, 6, 4},
                                    {7, 5}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(nodes[i]->row == (i / dimension));
      REQUIRE(nodes[i]->col == (i % dimension));
      REQUIRE(nodes[i]->distance == INFINITY);
      REQUIRE(nodes[i]->adjacent == adjacent[i]);
    }
  }

  SECTION("Testing the Constructor with a 2x2 board with walls") {
    vector<vector<int>> board = {{0, 0},
                                 {1, 0}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();
    vector<Graph::Node *> nodes = board_graph->GetNodes();

    vector<vector<int>> adjacent = {{1}, {3, 0}, {}, {1}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(nodes[i]->row == (i / dimension));
      REQUIRE(nodes[i]->col == (i % dimension));
      REQUIRE(nodes[i]->distance == INFINITY);
      REQUIRE(nodes[i]->adjacent == adjacent[i]);
    }
  }

  SECTION("Testing the Constructor with a 3x3 board with walls") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 1},
                                 {0, 1, 1}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();
    vector<Graph::Node *> nodes = board_graph->GetNodes();

    vector<vector<int>> adjacent = {{3, 1}, {4, 2, 0}, {1}, {6, 4, 0}, {3, 1},
                                    {}, {3}, {}, {}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(nodes[i]->row == (i / dimension));
      REQUIRE(nodes[i]->col == (i % dimension));
      REQUIRE(nodes[i]->distance == INFINITY);
      REQUIRE(nodes[i]->adjacent == adjacent[i]);
    }
  }

  SECTION("Testing the Constructor with a 3x3 board with walls and an"
          "unreachable node") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 1, 1},
                                 {0, 1, 0}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();
    vector<Graph::Node *> nodes = board_graph->GetNodes();

    vector<vector<int>> adjacent = {{3, 1}, {2, 0}, {1}, {6, 0}, {}, {}, {3},
                                    {}, {}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(nodes[i]->row == (i / dimension));
      REQUIRE(nodes[i]->col == (i % dimension));
      REQUIRE(nodes[i]->distance == INFINITY);
      REQUIRE(nodes[i]->adjacent == adjacent[i]);
    }
  }
}