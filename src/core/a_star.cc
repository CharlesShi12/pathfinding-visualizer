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

double AStar::Distance(int start_row, int start_col, int end_row, int end_col) {
  return std::abs(start_col - end_col) + std::abs(start_row - end_row);
}

vector<vector<int>> AStar::RunAStar(int end_row, int end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();

  // keep track of the nodes we have already visited
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // keep track of current costs at each node, essentially it stores the g
  // cost for each node
  vector<double> cost = vector<double>(dimension * dimension, 0.0);

  // stores the final shortest path for the algorithm
  vector<int> path = vector<int>(dimension * dimension);

  // create min-heap for the next nodes to visit
  priority_queue<pair<double, int>,
                 vector<pair<double, int>>,
                 std::greater<pair<double, int>>> next_nodes;

  // keep track of the end destination node id
  int end_node = 0;

  // initialize the data structures with the starting node
  size_t starting_node = 0;
  next_nodes.emplace(0.0, starting_node);
  cost[starting_node] = 0.0;
  path[starting_node] = starting_node;
  visited_nodes[starting_node] = true;

  while (!next_nodes.empty()) {
    // retrieve the current node's information
    int current_node_index = next_nodes.top().second;
    Graph::Node *current_node = nodes.at(current_node_index);
    visited_nodes[current_node_index] = true;

    next_nodes.pop();

    // check if this node is our final destination
    if (current_node->row == end_row && current_node->col == end_col) {
      end_node = current_node_index;
      break;
    }

    for (size_t neighbor : current_node->adjacent) {
      // compute the g cost for the neighbor nodes
      double neighbor_cost = cost[current_node_index] + 1;

      // check if the neighbor has been visited or if the current node has a
      // shorter cost than the previous nodes
      if (cost[neighbor] == 0.0 || neighbor_cost < cost[neighbor]) {
        path[neighbor] = current_node_index;
        Graph::Node *adjacent = nodes.at(neighbor);
        cost[neighbor] = neighbor_cost;

        // compute the f cost for the neighbor nodes which is the g cost
        // (movement from the starting node to the current node) plus the h cost
        // (heuristic movement from current node to end node)
        double f_neighbor_cost = neighbor_cost +
            Distance(adjacent->row, adjacent->col, end_row, end_col);
        next_nodes.emplace(f_neighbor_cost, neighbor);
      }
    }
  }

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = nodes.at(i);
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    }
  }

  // draw the final shortest path for the A* algorithm
  while (end_node != 0) {
    Graph::Node *node = nodes.at(end_node);
    output_board[node->row][node->col] = graph_algorithm::kPath;
    end_node = path[end_node];
  }

  return output_board;
}

}