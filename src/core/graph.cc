//
// Created by Charles Shi on 11/15/20.
//

#include "core/graph.h"

Graph::Graph(size_t dimension) {
  dimension_ = dimension;
}

void Graph::ConvertBoardToGraph(const vector<vector<int>> &board) {
  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      Node* node = new Node(row, col);
      nodes_.insert({col + row * dimension_, node});
    }
  }

  for (int row = 0; row < dimension_; row++) {
    for (int col = 0; col < dimension_; col++) {
      Node *current_node = nodes_[col + row * dimension_];
      if (board[row][col] == 0) {
        vector<vector<int>> positions = {{row - 1, col}, {row + 1, col},
                                         {row, col - 1}, {row, col + 1},
                                         {row - 1, col - 1}, {row + 1, col + 1},
                                         {row - 1, col + 1}, {row + 1, col - 1}};
        for (const vector<int> &position : positions) {
          int x = position[0];
          int y = position[1];
          if ((x > -1 && x < dimension_) && (y > -1 && y < dimension_)) {
            if (board[x][y] != 1) {
              current_node->adjacent.push_back(y + x * dimension_);
            }
          }
        }
      }
    }
  }
}

unordered_map<int, Graph::Node*> Graph::GetNodes() {
  return nodes_;
}