//
// Created by Charles Shi on 11/15/20.
//

#include <visualizer/sketchpad.h>
#include "core/graph.h"

namespace graph_algorithm {

Graph::Graph(const vector<vector<int>> &board) {
  board_ = board;
  dimension_ = board_.size();

  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      Node *node = new Node(row, col);
      nodes_.insert({col + row * dimension_, node});
    }
  }

  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      Node *current_node = nodes_[col + row * dimension_];
      if (board[row][col] != graph_algorithm::kWall) {
        vector<vector<int>> positions = {{row - 1, col - 1}, {row - 1, col},
                                         {row, col - 1}, {row + 1, col + 1},
                                         {row - 1, col + 1}, {row + 1, col},
                                         {row, col + 1}, {row + 1, col - 1}};
        for (const vector<int> &position : positions) {
          int x = position[0];
          int y = position[1];
          if ((x > -1 && x < dimension_) && (y > -1 && y < dimension_)) {
            if (board[x][y] != graph_algorithm::kWall) {
              current_node->adjacent.push_back(y + x * dimension_);
            }
          }
        }
      }
    }
  }
}

const unordered_map<int, Graph::Node *> &Graph::GetNodes() {
  return nodes_;
}

const vector<vector<int>> &Graph::GetBoard() {
  return board_;
}

size_t Graph::GetDimension() {
  return dimension_;
}

} // namespace graph_algorithm
