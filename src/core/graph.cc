//
// Created by Charles Shi on 11/15/20.
//

#include <visualizer/sketchpad.h>
#include <core/graph.h>

namespace graph_algorithm {

Graph::Graph(const vector<vector<int>> &board) {
  board_ = board;
  dimension_ = board_.size();

  // all of the possible positions the node is adjacent to
  vector<vector<int>> positions = {{1, 0}, {0, 1},
                                   {0, -1}, {-1, 0}};

  // insert all the new nodes into a map
  for (size_t row = 0; row < dimension_; row++) {
    for (size_t col = 0; col < dimension_; col++) {
      Node *node = new Node(row, col);
      nodes_.push_back(node);
    }
  }

  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      // get the current node we are modifying from the map
      Node *current_node = nodes_[col + row * dimension_];

      if (board[row][col] != graph_algorithm::kWall) {

        for (const vector<int> &position : positions) {
          int adjacent_row = position[0] + row;
          int adjacent_col = position[1] + col;

          // if it is a valid adjacent node and not a wall, then add to
          // adjacent list
          if ((adjacent_row > -1 && adjacent_row < dimension_) &&
              (adjacent_col > -1 && adjacent_col < dimension_) &&
              board[adjacent_row][adjacent_col] != graph_algorithm::kWall) {
              current_node->adjacent.push_back(adjacent_col +
                                               adjacent_row * dimension_);
          }
        }
      }
    }
  }
}

const vector<Graph::Node *> &Graph::GetNodes() {
  return nodes_;
}

const vector<vector<int>> &Graph::GetBoard() {
  return board_;
}

size_t Graph::GetDimension() {
  return dimension_;
}

} // namespace graph_algorithm