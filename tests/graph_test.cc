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

    REQUIRE(board_graph->GetDimension() == 2);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {2, 1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(0)->distance == INFINITY);

    adjacent = {3, 0};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(1)->distance == INFINITY);

    adjacent = {3, 0};
    REQUIRE(board_graph->GetNodes().at(2)->row == 1);
    REQUIRE(board_graph->GetNodes().at(2)->col == 0);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(2)->distance == INFINITY);

    adjacent = {2, 1};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 1);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(3)->distance == INFINITY);
  }

  SECTION("Testing the Constructor with a 3x3 board with no walls") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};

    auto *board_graph = new Graph(board);

    REQUIRE(board_graph->GetDimension() == 3);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {3, 1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(0)->distance == INFINITY);

    adjacent = {4, 2, 0};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(1)->distance == INFINITY);

    adjacent = {5, 1};
    REQUIRE(board_graph->GetNodes().at(2)->row == 0);
    REQUIRE(board_graph->GetNodes().at(2)->col == 2);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(2)->distance == INFINITY);

    adjacent = {6, 4, 0};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 0);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(3)->distance == INFINITY);

    adjacent = {7, 5, 3, 1};
    REQUIRE(board_graph->GetNodes().at(4)->row == 1);
    REQUIRE(board_graph->GetNodes().at(4)->col == 1);
    REQUIRE(board_graph->GetNodes().at(4)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(4)->distance == INFINITY);

    adjacent = {8, 4, 2};
    REQUIRE(board_graph->GetNodes().at(5)->row == 1);
    REQUIRE(board_graph->GetNodes().at(5)->col == 2);
    REQUIRE(board_graph->GetNodes().at(5)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(5)->distance == INFINITY);

    adjacent = {7, 3};
    REQUIRE(board_graph->GetNodes().at(6)->row == 2);
    REQUIRE(board_graph->GetNodes().at(6)->col == 0);
    REQUIRE(board_graph->GetNodes().at(6)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(6)->distance == INFINITY);

    adjacent = {8, 6, 4};
    REQUIRE(board_graph->GetNodes().at(7)->row == 2);
    REQUIRE(board_graph->GetNodes().at(7)->col == 1);
    REQUIRE(board_graph->GetNodes().at(7)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(7)->distance == INFINITY);

    adjacent = {7, 5};
    REQUIRE(board_graph->GetNodes().at(8)->row == 2);
    REQUIRE(board_graph->GetNodes().at(8)->col == 2);
    REQUIRE(board_graph->GetNodes().at(8)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(8)->distance == INFINITY);
  }

  SECTION("Testing the Constructor with a 2x2 board with walls") {
    vector<vector<int>> board = {{0, 0},
                                 {1, 0}};

    auto *board_graph = new Graph(board);

    REQUIRE(board_graph->GetDimension() == 2);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(0)->distance == INFINITY);

    adjacent = {3, 0};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(1)->distance == INFINITY);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(2)->row == 1);
    REQUIRE(board_graph->GetNodes().at(2)->col == 0);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(2)->distance == INFINITY);

    adjacent = {1};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 1);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(3)->distance == INFINITY);
  }

  SECTION("Testing the Constructor with a 3x3 board with walls") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 1},
                                 {0, 1, 1}};

    auto *board_graph = new Graph(board);

    REQUIRE(board_graph->GetDimension() == 3);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {3, 1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(0)->distance == INFINITY);

    adjacent = {4, 2, 0};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(1)->distance == INFINITY);

    adjacent = {1};
    REQUIRE(board_graph->GetNodes().at(2)->row == 0);
    REQUIRE(board_graph->GetNodes().at(2)->col == 2);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(2)->distance == INFINITY);

    adjacent = {6, 4, 0};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 0);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(3)->distance == INFINITY);

    adjacent = {3, 1};
    REQUIRE(board_graph->GetNodes().at(4)->row == 1);
    REQUIRE(board_graph->GetNodes().at(4)->col == 1);
    REQUIRE(board_graph->GetNodes().at(4)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(4)->distance == INFINITY);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(5)->row == 1);
    REQUIRE(board_graph->GetNodes().at(5)->col == 2);
    REQUIRE(board_graph->GetNodes().at(5)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(5)->distance == INFINITY);

    adjacent = {3};
    REQUIRE(board_graph->GetNodes().at(6)->row == 2);
    REQUIRE(board_graph->GetNodes().at(6)->col == 0);
    REQUIRE(board_graph->GetNodes().at(6)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(6)->distance == INFINITY);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(7)->row == 2);
    REQUIRE(board_graph->GetNodes().at(7)->col == 1);
    REQUIRE(board_graph->GetNodes().at(7)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(7)->distance == INFINITY);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(8)->row == 2);
    REQUIRE(board_graph->GetNodes().at(8)->col == 2);
    REQUIRE(board_graph->GetNodes().at(8)->adjacent == adjacent);
    REQUIRE(board_graph->GetNodes().at(8)->distance == INFINITY);
  }

  SECTION("Testing the Constructor with a 3x3 board with walls and an"
          "unreachable node") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 1, 1},
                                 {0, 1, 0}};

    auto *board_graph = new Graph(board);
    size_t dimension = board_graph->GetDimension();

    vector<vector<int>> adjacent = {{3, 1}, {2, 0}, {1}, {6, 0}, {}, {}, {3},
                                    {}, {}};

    for (size_t i = 0; i < dimension; i++) {
      REQUIRE(board_graph->GetNodes()[i]->row == (i / dimension));
      REQUIRE(board_graph->GetNodes()[i]->col == (i % dimension));
      REQUIRE(board_graph->GetNodes()[i]->distance == INFINITY);
      REQUIRE(board_graph->GetNodes()[i]->adjacent == adjacent[i]);
    }
  }
}