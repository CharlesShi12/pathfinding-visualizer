//
// Created by Charles Shi on 11/28/20.
//

#include "core/a_star.h"
#include <map>

namespace graph_algorithm {

using std::priority_queue;
using std::pair;
using std::unordered_map;
using std::vector;

double AStar::Distance(size_t start_row, size_t start_col, size_t end_row,
                       size_t end_col) {
  return sqrt((end_col - start_col) * (end_col - start_col) +
              (end_row - start_row) * (end_row - start_row));
}

vector<vector<int>> AStar::Find(size_t end_row, size_t end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();

  // keep track of the nodes we have already visited
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // stores the parent node for the current node
  vector<size_t> path = vector<size_t>(dimension * dimension, -1);

  // create min-heap for the next nodes to visit based on the smallest f cost
  // the heap sorts from lowest to highest for the first element of the pair
  priority_queue<pair<double, size_t>,
                 vector<pair<double, size_t>>,
                 std::greater<pair<double, size_t>>> next_nodes;

  // keep track of the end destination node id
  size_t end_node_index = 0;

  // adding the starting node to the data structures
  size_t starting_node_index = 0;
  next_nodes.emplace(0.0, starting_node_index);
  path[starting_node_index] = starting_node_index;
  visited_nodes[starting_node_index] = true;

  // set starting distance to 0
  Graph::Node *start_node = nodes.at(starting_node_index);
  start_node->distance = 0;

  while (!next_nodes.empty()) {
    // retrieve the current node's information
    size_t current_node_index = next_nodes.top().second;
    Graph::Node *current_node = nodes.at(current_node_index);
    visited_nodes[current_node_index] = true;

    next_nodes.pop();

    // check if this node is our final destination
    if (current_node->row == end_row && current_node->col == end_col) {
      end_node_index = current_node_index;
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

        // compute the f cost which is the g cost (movement from the starting
        // node to the current node) plus the h cost (heuristic movement from
        // current node to end node)
        double neighbor_f_cost = adjacent->distance +
            Distance(adjacent->row + 1, adjacent->col + 1,
                     end_row + 1, end_col + 1);
        next_nodes.emplace(neighbor_f_cost, neighbor);
      }
    }
  }

  // traverse the board to find the shortest path
  vector<Graph::Node *> output_path;
  while (end_node_index != 0) {
    Graph::Node *node = nodes[end_node_index];
    output_path.push_back(node);
    end_node_index = path[end_node_index];
  }

  return ConstructBoard(visited_nodes, output_path);
}

} // namespace graph_algorithm