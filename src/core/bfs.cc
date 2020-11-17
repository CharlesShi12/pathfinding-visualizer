//
// Created by Charles Shi on 11/15/20.
//

#include <core/graph.h>
#include <queue>
#include <visualizer/sketchpad.h>
#include "core/bfs.h"

namespace graph_algorithm {

namespace bfs {

BFS::BFS(Graph *board_graph) {
  board_graph_ = board_graph;
}

vector<vector<int>> BFS::RunBFS(size_t end_row, size_t end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();

  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);
  std::queue<int> next_nodes;

  size_t first_node = 0;
  next_nodes.push(first_node);

  while (!next_nodes.empty()) {
    Graph::Node *vertex = board_graph_->GetNodes().at(next_nodes.front());
    visited_nodes[next_nodes.front()] = true;
    next_nodes.pop();

    if (vertex->row == end_row && vertex->col == end_col) {
      break;
    }

    for (int neighbor : vertex->adjacent) {
      if (!visited_nodes[neighbor]) {
        next_nodes.push(neighbor);
      }
    }
  }

  for (int i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = board_graph_->GetNodes().at(i);
      output_board[node->row][node->col] = graph_algorithm::kPath;
    }
  }
  return output_board;
}

} // namespace bfs

} // namespace graph_algorithm