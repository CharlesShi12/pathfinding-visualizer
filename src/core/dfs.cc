//
// Created by Charles Shi on 11/16/20.
//

#include <visualizer/sketchpad.h>
#include <core/dfs.h>

namespace graph_algorithm {

// Todo: Output path

bool DFS::RecursiveDFS(size_t node_index, size_t end_row, size_t end_col,
                       vector<bool> &visited_nodes, vector<Graph::Node*> &path) {
  if (visited_nodes[node_index]) {
    return false;
  }
  Graph::Node *current_node = board_graph_->GetNodes()[node_index];
  visited_nodes[node_index] = true;
  path.push_back(current_node);
//  if (!found_destination_) {

    // stop visiting other nodes once we have found the destination node
    if (current_node->row == end_row && current_node->col == end_col) {
      return true;

    } else {
      // recursively iterate through the current node's adjacent nodes
      for (size_t neighbor : current_node->adjacent) {
//        if (!visited_nodes[neighbor]) {
//          path[neighbor] = node_index;
//          visited_nodes[node_index] = true;
          if (RecursiveDFS(neighbor, end_row, end_col, visited_nodes, path)) {
            return true;
          }
//        }
      }
    }
//  }
//  if (!found_destination_) {
    path.pop_back();
    return false;
//  }
}

vector<vector<int>> DFS::Find(size_t end_row, size_t end_col) {
  size_t dimension = board_graph_->GetDimension();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();
  vector<vector<int>> output_board = board_graph_->GetBoard();
  vector<Graph::Node*> path;

  // keeps track of every node we visit
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // run the DFS recursion on the first node (0)
  RecursiveDFS(0, end_row, end_col, visited_nodes, path);

//  // update the output board to show the nodes we've visited from the start to
//  // find the end destination
//  for (size_t i = 0; i < dimension * dimension; i++) {
//    if (visited_nodes[i]) {
//      Graph::Node *node = board_graph_->GetNodes()[i];
//      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
//    }
//  }

//  vector<Graph::Node *> shortest_path;
//  int end_node = end_row * dimension + end_col;
//
//  while (end_node != 0) {
//    Graph::Node *node = nodes[end_node];
//    shortest_path.push_back(node);
//    end_node = path[end_node];
//  }

  return ConstructBoard(visited_nodes, path);
}

} // namespace graph_algorithm