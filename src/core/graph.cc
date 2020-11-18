//
// Created by Charles Shi on 11/15/20.
//

#include <visualizer/sketchpad.h>
#include "core/graph.h"

namespace graph_algorithm {

Graph::Graph(const vector<vector<int>> &board) {
  board_ = board;
  dimension_ = board_.size();

  // insert all the new nodes into a map
  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      Node *node = new Node(row, col);
      nodes_.insert({col + row * dimension_, node});
    }
  }

  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      // get the current node we are modifying from the map
      Node *current_node = nodes_[col + row * dimension_];

      if (board[row][col] != graph_algorithm::kWall) {
        // all of the possible positions the node is adjacent to
        vector<vector<int>> positions = {{row - 1, col - 1}, {row - 1, col},
                                         {row, col - 1}, {row + 1, col + 1},
                                         {row - 1, col + 1}, {row, col + 1},
                                         {row + 1, col}, {row + 1, col - 1}};

        for (const vector<int> &position : positions) {
          int row = position[0];
          int col = position[1];

          // if it is a valid adjacent node and not marked, then add to
          // adjacent list
          if ((row > -1 && row < dimension_) && (col > -1 && col < dimension_)) {
            if (board[row][col] != graph_algorithm::kWall) {
              current_node->adjacent.push_back(col + row * dimension_);
            }
          }
        }
      }
    }
  }
}

const unordered_map<size_t, Graph::Node *> &Graph::GetNodes() {
  return nodes_;
}

const vector<vector<int>> &Graph::GetBoard() {
  return board_;
}

size_t Graph::GetDimension() {
  return dimension_;
}

} // namespace graph_algorithm
