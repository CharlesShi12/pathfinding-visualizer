//
// Created by Charles Shi on 12/3/20.
//

#include "core/bidirectional_bfs.h"
#include <core/graph.h>
#include <visualizer/sketchpad.h>
#include <queue>

namespace graph_algorithm {

using std::queue;

void BidirectionalBFS::BFS(queue<size_t> &next_nodes, vector<bool> &visited_nodes) {
  Graph::Node *current_node = board_graph_->GetNodes()[next_nodes.front()];
  visited_nodes[next_nodes.front()] = true;
  next_nodes.pop();

  for (size_t neighbor : current_node->adjacent) {
    if (!visited_nodes[neighbor]) {
      next_nodes.push(neighbor);
      Graph::Node *adjacent = board_graph_->GetNodes()[neighbor];
      adjacent->distance = current_node->distance + 1;
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

  queue<size_t> start_next_nodes;
  queue<size_t> end_next_nodes;

  size_t starting_node = 0;
  start_next_nodes.push(starting_node);
  Graph::Node *start = nodes[starting_node];
  start->distance = 0;

  size_t ending_node = end_row * dimension + end_col;
  end_next_nodes.push(ending_node);
  Graph::Node *end = nodes[ending_node];
  end->distance = 0;

  int intersection_node_index = -1;

  while (!start_next_nodes.empty() && !end_next_nodes.empty()) {
    BFS(start_next_nodes, start_visited_nodes);
    BFS(end_next_nodes, end_visited_nodes);
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

  if (intersection_node_index == -1) {
    return output_board;
  }

  return output_board;
}

} // namespace graph_algorithm
