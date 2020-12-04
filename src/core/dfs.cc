//
// Created by Charles Shi on 11/16/20.
//

#include <visualizer/sketchpad.h>
#include <core/dfs.h>

namespace graph_algorithm {

void DFS::RecursiveDFS(size_t node_index, size_t end_row, size_t end_col,
                       vector<bool> &visited_nodes) {
  if (!found_destination_) {
    visited_nodes[node_index] = true;
    Graph::Node *current_node = board_graph_->GetNodes()[node_index];

    // stop visiting other nodes once we have found the destination node
    if (current_node->row == end_row && current_node->col == end_col) {
      found_destination_ = true;

    } else {
      // recursively iterate through the current node's adjacent nodes
      for (size_t neighbor : current_node->adjacent) {
        if (!visited_nodes[neighbor]) {
          RecursiveDFS(neighbor, end_row, end_col, visited_nodes);
        }
      }
    }
  }
}

vector<vector<int>> DFS::Find(size_t end_row, size_t end_col) {
  size_t dimension = board_graph_->GetDimension();
  vector<vector<int>> output_board = board_graph_->GetBoard();

  // keeps track of every node we visit
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // run the DFS recursion on the first node (0)
  RecursiveDFS(0, end_row, end_col, visited_nodes);

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = board_graph_->GetNodes()[i];
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    }
  }

  return output_board;
}

} // namespace graph_algorithm