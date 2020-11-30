//
// Created by Charles Shi on 11/28/20.
//

#include "core/a_star.h"
#include <queue>
#include <map>
#include <visualizer/sketchpad.h>

//TODO: Ask if I should split the functions into a "Draw A*" function (lines 93-105)

namespace graph_algorithm {

using std::priority_queue;
using std::pair;
using std::unordered_map;

AStar::AStar(Graph *board_graph) {
  board_graph_ = board_graph;
}

double AStar::Distance(int start_row, int start_col, int end_row, int end_col) {
  return sqrt((start_col - end_col) * (start_col - end_col) +
              (start_row - end_row) * (start_row - end_row));
}

vector<vector<int>> AStar::RunAStar(int end_row, int end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();

  // keep track of the nodes we have already visited
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // stores the final shortest path for the algorithm
  vector<int> path = vector<int>(dimension * dimension, -1);

  // create min-heap for the next nodes to visit based on the smallest f cost
  // the heap sorts from lowest to highest for the first element of the pair
  priority_queue<pair<double, int>,
                 vector<pair<double, int>>,
                 std::greater<pair<double, int>>> next_nodes;

  // keep track of the end destination node id
  int end_node = 0;

  // adding the starting node to the data structures
  size_t starting_node = 0;
  next_nodes.emplace(0.0, starting_node);
  path[starting_node] = starting_node;
  visited_nodes[starting_node] = true;

  // set starting distance to 0
  Graph::Node *start = nodes.at(starting_node);
  start->distance = 0;

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
      // only add the node if it hasn't been traversed
      if (path[neighbor] == -1) {
        // compute the g cost for the neighbor node
        Graph::Node *adjacent = nodes.at(neighbor);
        adjacent->distance = current_node->distance + 1;

        // update the path so that we can backtrack from the end to start for
        // the final shortest path
        path[neighbor] = current_node_index;

        // compute the f cost for the neighbor nodes which is the g cost
        // (movement from the starting node to the current node) plus the h cost
        // (heuristic movement/Euclidean distance from current node to end node)
        double neighbor_f_cost = adjacent->distance +
            Distance(adjacent->row + 1, adjacent->col + 1,
                     end_row + 1, end_col + 1);
        next_nodes.emplace(neighbor_f_cost, neighbor);
      }
    }
  }

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = nodes[i];
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;
    }
  }

  // draw the final shortest path for the A* algorithm
  while (end_node != 0) {
    Graph::Node *node = nodes[end_node];
    output_board[node->row][node->col] = graph_algorithm::kPath;
    end_node = path[end_node];
  }

  return output_board;
}

}