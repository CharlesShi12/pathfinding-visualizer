//
// Created by Charles Shi on 11/16/20.
//

#include "core/dfs.h"

DFS::DFS(const vector<vector<int>> &board) {
  board_ = board;
  dimension_ = board_.size();
  found_destination_ = false;

  Graph* graph_board = new Graph(dimension_);
  graph_board->ConvertBoardToGraph(board);
  nodes_ = graph_board->GetNodes();
}

void DFS::RecursiveDFS(int node, size_t end_row, size_t end_col, vector<bool> &visited_nodes) {
  if (!found_destination_) {
    visited_nodes[node] = true;
    if (nodes_.at(node)->row == end_row && nodes_.at(node)->col == end_col) {
      found_destination_ = true;
    }
    for (int i : nodes_.at(node)->adjacent) {
      if (!visited_nodes[i]) {
        RecursiveDFS(i, end_row, end_col, visited_nodes);
      }
    }
  }

}

vector<vector<int>> DFS::RunDFS(size_t end_row, size_t end_col) {
  vector<vector<int>> output_board = board_;
  vector<bool> visited_nodes = vector<bool>(dimension_ * dimension_, false);

  RecursiveDFS(0, end_row, end_col, visited_nodes);

  for (int i = 0; i < dimension_ * dimension_; i++) {
    if(visited_nodes[i]) {
      Graph::Node* node = nodes_.at(i);
      output_board[node->row][node->col] = 2;
    }
  }

  return output_board;
}

