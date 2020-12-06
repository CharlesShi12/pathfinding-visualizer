//
// Created by Charles Shi on 11/16/20.
//

#include <core/dfs.h>

namespace graph_algorithm {

using std::vector;

bool DFS::RecursiveDFS(size_t current_node_index, size_t end_row, size_t end_col,
                       vector<bool> &visited_nodes, vector<Graph::Node*> &path) {
  if (visited_nodes[current_node_index]) {
    return false;
  }

  Graph::Node *current_node = board_graph_->GetNodes()[current_node_index];
  visited_nodes[current_node_index] = true;
  path.push_back(current_node);

  // stop visiting other nodes once we have found the destination node
  if (current_node->row == end_row && current_node->col == end_col) {
    return true;

  } else {
    // recursively iterate through the current node's adjacent nodes and run DFS
    for (size_t neighbor : current_node->adjacent) {
      if (RecursiveDFS(neighbor, end_row, end_col, visited_nodes, path)) {
        return true;
      }
    }
  }

  path.pop_back();
  return false;
}

vector<vector<int>> DFS::Find(size_t end_row, size_t end_col) {
  size_t dimension = board_graph_->GetDimension();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();
  vector<vector<int>> output_board = board_graph_->GetBoard();

  vector<Graph::Node*> output_path;

  // keeps track of every node we visit
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // run the DFS recursion starting with the first node
  RecursiveDFS(0, end_row, end_col, visited_nodes, output_path);

  return ConstructBoard(visited_nodes, output_path);
}

} // namespace graph_algorithm