//
// Created by Charles Shi on 12/3/20.
//

#include "core/bidirectional_bfs.h"
#include <core/graph.h>
#include <visualizer/sketchpad.h>
#include <queue>

namespace graph_algorithm {

using std::queue;

// todo : potentially make the output path into a function?
// todo : potentially make the shortest path into a private function?

void BidirectionalBFS::BFS(queue<size_t> &next_nodes, vector<bool> &visited_nodes, vector<int> &path) {
  int current_node_index = next_nodes.front();
  Graph::Node *current_node = board_graph_->GetNodes()[next_nodes.front()];
  next_nodes.pop();

  for (size_t neighbor : current_node->adjacent) {
    if (!visited_nodes[neighbor]) {
      visited_nodes[neighbor] = true;
      next_nodes.push(neighbor);
      path[neighbor] = current_node_index;
    }
  }
}

int BidirectionalBFS::IsCollided(vector<bool> start_visited_nodes,
                                 vector<bool> end_visited_nodes) {
  for (int i = 0; i < start_visited_nodes.size(); i++) {
    if (start_visited_nodes[i] && end_visited_nodes[i]) {
      return i;
    }
  }
  return -1;
}

vector<vector<int>> BidirectionalBFS::Find(size_t end_row, size_t end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();
  size_t dimension = board_graph_->GetDimension();

  vector<bool> start_visited_nodes = vector<bool>(dimension * dimension, false);
  vector<bool> end_visited_nodes = vector<bool>(dimension * dimension, false);

  vector<int> start_path = vector<int>(dimension * dimension, -1);
  vector<int> end_path = vector<int>(dimension * dimension, -1);

  queue<size_t> start_next_nodes;
  queue<size_t> end_next_nodes;

  size_t starting_node = 0;
  start_next_nodes.push(starting_node);
  start_visited_nodes[0] = true;

  size_t ending_node = end_row * dimension + end_col;
  end_next_nodes.push(ending_node);
  end_visited_nodes[ending_node] = true;

  int intersection_node_index;

  while (!start_next_nodes.empty() && !end_next_nodes.empty()) {
    BFS(start_next_nodes, start_visited_nodes, start_path);
    BFS(end_next_nodes, end_visited_nodes, end_path);
    intersection_node_index = IsCollided(start_visited_nodes, end_visited_nodes);
    if (intersection_node_index != -1) {
      break;
    }
  }

  for (size_t i = 0; i < dimension * dimension; i++) {
    Graph::Node *node = nodes[i];
    if (start_visited_nodes[i]) {
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    } else if (end_visited_nodes[i]) {
      output_board[node->row][node->col] = graph_algorithm::kAlternativeTraversedNodes;
    }
  }

  vector<Graph::Node *> shortest_path;

  int curr_node_index = intersection_node_index;

  while (curr_node_index != 0) {
    Graph::Node *node = nodes[curr_node_index];
    shortest_path.push_back(node);
    curr_node_index = start_path[curr_node_index];
  }

  curr_node_index = intersection_node_index;

  while (curr_node_index != (end_row * dimension + end_col)) {
    Graph::Node *node = nodes[curr_node_index];
    shortest_path.push_back(node);
    curr_node_index = end_path[curr_node_index];
  }

  for (Graph::Node *final_path : shortest_path) {
    output_board[final_path->row][final_path->col] = kPath;
  }

  output_board[intersection_node_index / dimension][intersection_node_index % dimension] = kIntersectionNode;

  return output_board;
}

} // namespace graph_algorithm