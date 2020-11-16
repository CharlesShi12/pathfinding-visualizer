#include <core/bfs_algorithm.h>
#include <queue>

namespace algorithm {

BFS::BFS(int dimensions) {
  dimensions_ = dimensions;
}

void BFS::ConvertBoardToGraph(const vector<vector<int>> &board) {
  for (int row = 0; row < dimensions_; row++) {
    for (int col = 0; col < dimensions_; col++) {
      Node* node = new Node(row, col);
      nodes_.insert({col + row * dimensions_, node});
    }
  }

  for (int row = 0; row < dimensions_; row++) {
    for (int col = 0; col < dimensions_; col++) {
      Node *current_node = nodes_[col + row * dimensions_];
      if (board[row][col] == 0) {
        vector<vector<int>> positions = {{row - 1, col}, {row + 1, col},
                                         {row, col - 1}, {row, col + 1},
                                         {row - 1, col - 1}, {row + 1, col + 1},
                                         {row - 1, col + 1}, {row + 1, col - 1}};
        for (const vector<int> &position : positions) {
          int x = position[0];
          int y = position[1];
          if ((x > -1 && x < dimensions_) && (y > -1 && y < dimensions_)) {
            if (board[x][y] != 1) {
              current_node->adjacent.push_back(y + x * dimensions_);
            }
          }
        }
      }
    }
  }
}

}  // namespace algorithm