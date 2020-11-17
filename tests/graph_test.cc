//
// Created by Charles Shi on 11/17/20.
//

#include <catch2/catch.hpp>
#include <core/graph.h>
#include <vector>

using std::vector;
using graph_algorithm::Graph;

TEST_CASE("Testing the Graph class") {
  SECTION("Testing the Constructor with a 2x2 board") {
    vector<vector<int>> board = {{0, 0},
                                 {1, 0}};

    Graph *board_graph = new Graph(board);

    REQUIRE(board_graph->GetDimension() == 2);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {3, 1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);

    adjacent = {0, 3};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(2)->row == 1);
    REQUIRE(board_graph->GetNodes().at(2)->col == 0);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);

    adjacent = {0, 1};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 1);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);
  }

  SECTION("Testing the Constructor with a 3x3 board") {
    vector<vector<int>> board = {{0, 0, 0},
                                 {0, 0, 1},
                                 {0, 1, 1}};

    Graph *board_graph = new Graph(board);

    REQUIRE(board_graph->GetDimension() == 3);
    REQUIRE(board_graph->GetBoard() == board);

    vector<int> adjacent = {4, 3, 1};
    REQUIRE(board_graph->GetNodes().at(0)->row == 0);
    REQUIRE(board_graph->GetNodes().at(0)->col == 0);
    REQUIRE(board_graph->GetNodes().at(0)->adjacent == adjacent);

    adjacent = {0, 4, 2, 3};
    REQUIRE(board_graph->GetNodes().at(1)->row == 0);
    REQUIRE(board_graph->GetNodes().at(1)->col == 1);
    REQUIRE(board_graph->GetNodes().at(1)->adjacent == adjacent);

    adjacent = {1, 4};
    REQUIRE(board_graph->GetNodes().at(2)->row == 0);
    REQUIRE(board_graph->GetNodes().at(2)->col == 2);
    REQUIRE(board_graph->GetNodes().at(2)->adjacent == adjacent);

    adjacent = {0, 1, 6, 4};
    REQUIRE(board_graph->GetNodes().at(3)->row == 1);
    REQUIRE(board_graph->GetNodes().at(3)->col == 0);
    REQUIRE(board_graph->GetNodes().at(3)->adjacent == adjacent);

    adjacent = {0, 1, 3, 2, 6};
    REQUIRE(board_graph->GetNodes().at(4)->row == 1);
    REQUIRE(board_graph->GetNodes().at(4)->col == 1);
    REQUIRE(board_graph->GetNodes().at(4)->adjacent == adjacent);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(5)->row == 1);
    REQUIRE(board_graph->GetNodes().at(5)->col == 2);
    REQUIRE(board_graph->GetNodes().at(5)->adjacent == adjacent);

    adjacent = {3, 4};
    REQUIRE(board_graph->GetNodes().at(6)->row == 2);
    REQUIRE(board_graph->GetNodes().at(6)->col == 0);
    REQUIRE(board_graph->GetNodes().at(6)->adjacent == adjacent);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(7)->row == 2);
    REQUIRE(board_graph->GetNodes().at(7)->col == 1);
    REQUIRE(board_graph->GetNodes().at(7)->adjacent == adjacent);

    adjacent = {};
    REQUIRE(board_graph->GetNodes().at(8)->row == 2);
    REQUIRE(board_graph->GetNodes().at(8)->col == 2);
    REQUIRE(board_graph->GetNodes().at(8)->adjacent == adjacent);
  }
}
