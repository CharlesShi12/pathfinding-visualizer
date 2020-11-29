//
// Created by Charles Shi on 11/28/20.
//

#include "core/a_star.h"
#include <queue>
#include <map>
#include <visualizer/sketchpad.h>

namespace graph_algorithm {

using std::priority_queue;
using std::pair;
using std::unordered_map;

AStar::AStar(Graph *board_graph) {
  board_graph_ = board_graph;
}

double AStar::Distance(Graph::Node *start, int end_row, int end_col) {
  return std::abs(start->col - end_col) + std::abs(start->row - end_row);
}

vector<vector<int>> AStar::RunAStar(int end_row, int end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();

  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);
  vector<double> cost_so_far = vector<double>(dimension * dimension, 0.0);
  vector<int> path = vector<int>(dimension * dimension);

  priority_queue<pair<double, int>, vector<pair<double, int>>, std::greater<pair<double, int>>> queue;

  size_t first_node = 0;

  queue.emplace(0.0, first_node);

  path[first_node] = first_node;
  visited_nodes[first_node] = true;
  cost_so_far[first_node] = 0.0;
  int end_node = 0;

  while(!queue.empty()) {
    int index = queue.top().second;
    Graph::Node *vertex = board_graph_->GetNodes().at(index);
    visited_nodes[index] = true;

    queue.pop();

    if (vertex->row == end_row && vertex->col == end_col) {
      end_node = index;
      break;
    }

    for (size_t neighbor : vertex->adjacent) {
      double new_cost = cost_so_far[index] + 1;
      if (cost_so_far[neighbor] == 0 || new_cost < cost_so_far[neighbor]) {
        Graph::Node *adjacent = board_graph_->GetNodes().at(neighbor);
        cost_so_far[neighbor] = new_cost;
        double priority = new_cost + Distance(adjacent, end_row, end_col);
        queue.emplace(priority, neighbor);
        path[neighbor] = index;
      }
    }
  }

  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = board_graph_->GetNodes().at(i);
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    }
  }
g

  return output_board;

}

}