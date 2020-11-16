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

vector<vector<int>> BFS::RunBFS(const vector<vector<int>> &board, size_t end_row, size_t end_col) {
  ConvertBoardToGraph(board);

  vector<vector<int>> output_board = board;
  vector<bool> visited_nodes = vector<bool>(dimensions_ * dimensions_, false);
  std::queue<int> next_nodes;
  size_t first_node = 0;

  next_nodes.push(first_node);
  visited_nodes[first_node] = true;

  while(!next_nodes.empty()) {
    Node* vertex = nodes_.at(next_nodes.front());
    visited_nodes[next_nodes.front()] = true;
    next_nodes.pop();

    if (vertex->row == end_row && vertex->col == end_col) {
      break;
    }

    for(int neighbor : vertex->adjacent) {
      if(!visited_nodes[neighbor]) {
        next_nodes.push(neighbor);
      }
    }
  }

  for (int i = 0; i < dimensions_ * dimensions_; i++) {
    if(visited_nodes[i]) {
      Node* node = nodes_.at(i);
      output_board[node->row][node->col] = 2;
    }
  }
  return output_board;
}

}  // namespace algorithm