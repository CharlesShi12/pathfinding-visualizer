//
// Created by Charles Shi on 11/15/20.
//

#include <core/graph.h>
#include <queue>
#include "core/bfs.h"

BFS::BFS(const vector<vector<int>> &board) {
  board_ = board;
  dimension_ = board_.size();
}

vector<vector<int>> BFS::RunBFS(size_t end_row, size_t end_col) {
  Graph* graph_board = new Graph(dimension_);

  graph_board->ConvertBoardToGraph(board_);
  vector<vector<int>> output_board = board_;

  vector<bool> visited_nodes = vector<bool>(dimension_ * dimension_, false);
  std::queue<int> next_nodes;
  size_t first_node = 0;

  next_nodes.push(first_node);
  visited_nodes[first_node] = true;

  while(!next_nodes.empty()) {
    Graph::Node* vertex = graph_board->GetNodes().at(next_nodes.front());
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

  for (int i = 0; i < dimension_ * dimension_; i++) {
    if(visited_nodes[i]) {
      Graph::Node* node = graph_board->GetNodes().at(i);
      output_board[node->row][node->col] = 2;
    }
  }
  return output_board;
}