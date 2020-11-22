//
// Created by Charles Shi on 11/16/20.
//

#include <visualizer/sketchpad.h>
#include <core/dfs.h>

namespace graph_algorithm {

DFS::DFS(Graph *board_graph) {
  board_graph_ = board_graph;
  found_destination_ = false;
}

void DFS::RecursiveDFS(size_t node_index, size_t end_row, size_t end_col,
                       vector<bool> &visited_nodes) {
  if (!found_destination_) {
    visited_nodes[node_index] = true;
    Graph::Node *node = board_graph_->GetNodes().at(node_index);

    // stop visiting other nodes once we have found the destination node
    if (node->row == end_row && node->col == end_col) {
      found_destination_ = true;

    } else {
      // recursively iterate through the current node's adjacent nodes
      for (size_t neighbor : node->adjacent) {
        if (!visited_nodes[neighbor]) {
          RecursiveDFS(neighbor, end_row, end_col, visited_nodes);
        }
      }
    }
  }
}

//vector<Graph::Node *> DFS::LocatePath(const vector<vector<int>> &board_graph) {
//  Graph::Node *node = path_.back();
//  if (node->row == 0 && node->col == 0) {
//    return path_;
//  } else {
//    float min_distance = INFINITY;
//    Graph::Node *path_node = node;
//    for (size_t adjacent_node_index : node->adjacent) {
//      Graph::Node *adjacent_node = board_graph_->GetNodes().at(adjacent_node_index);
//      if (board_graph[adjacent_node->row][adjacent_node->col] == kPath) {
//        float current_distance = sqrt(pow(adjacent_node->row - 0, 2) +
//            pow(adjacent_node->col- 0, 2) * 1.0);
//        if (current_distance < min_distance) {
//          path_node = adjacent_node;
//        }
//      }
//    }
//    path_.push_back(path_node);
//  }
//  return LocatePath(board_graph);
//}

vector<vector<int>> DFS::RunDFS(size_t end_row, size_t end_col) {
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
      Graph::Node *node = board_graph_->GetNodes().at(i);
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    }
  }

//  LocatePath(output_board);
  return output_board;
}

} // namespace graph_algorithm