//
// Created by Charles Shi on 12/3/20.
//

#include "core/bidirectional_bfs.h"
#include <core/graph.h>
#include <visualizer/sketchpad.h>

namespace graph_algorithm {

using std::queue;
using std::vector;

void BidirectionalBFS::BFS(queue<size_t> &next_nodes,
                           vector<bool> &visited_nodes, vector<size_t> &parent) {
  size_t current_node_index = next_nodes.front();
  Graph::Node *current_node = board_graph_->GetNodes()[current_node_index];
  next_nodes.pop();

  // add the adjacent nodes to the queue if we haven't visited/added them
  for (size_t neighbor : current_node->adjacent) {
    if (!visited_nodes[neighbor]) {
      visited_nodes[neighbor] = true;
      next_nodes.push(neighbor);
      parent[neighbor] = current_node_index;
    }
  }
}

int BidirectionalBFS::CollisionNode(const vector<bool> &start_visited_nodes,
                                    const vector<bool> &end_visited_nodes) {
  for (size_t i = 0; i < start_visited_nodes.size(); i++) {
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

  // keep track of the nodes we have already visited for both start and end
  // breadth first searches
  vector<bool> start_visited_nodes = vector<bool>(dimension * dimension, false);
  vector<bool> end_visited_nodes = vector<bool>(dimension * dimension, false);

  // keep track of the parent nodes for every node for both start and end
  // breadth first searches
  vector<size_t> start_parent = vector<size_t>(dimension * dimension, -1);
  vector<size_t> end_parent = vector<size_t>(dimension * dimension, -1);

  // create a queue of nodes to visit next for both start and end breadth first
  // searches
  queue<size_t> start_next_nodes;
  queue<size_t> end_next_nodes;

  // add the start node to the start data structures for BFS
  size_t start_node_index = 0;
  start_next_nodes.push(start_node_index);
  start_visited_nodes[0] = true;

  // add the end node to the end data structures for BFS
  size_t end_node_index = end_row * dimension + end_col;
  end_next_nodes.push(end_node_index);
  end_visited_nodes[end_node_index] = true;

  int intersection_node_index;

  while (!start_next_nodes.empty() && !end_next_nodes.empty()) {
    BFS(start_next_nodes, start_visited_nodes, start_parent);
    BFS(end_next_nodes, end_visited_nodes, end_parent);

    // find the node, if there is a node, that the start and end breadth first
    // searches collided with
    intersection_node_index = CollisionNode(start_visited_nodes, end_visited_nodes);
    if (intersection_node_index != -1) {
      // stop traversing if start and end breadth first searches collide
      break;
    }
  }

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    Graph::Node *node = nodes[i];

    if (start_visited_nodes[i]) {
      output_board[node->row][node->col] = graph_algorithm::kTraversedNodes;

    } else if (end_visited_nodes[i]) {
      output_board[node->row][node->col] =
          graph_algorithm::kAlternativeTraversedNodes;
    }
  }

  // if the end node was not traversed, do not output a final path
  if (intersection_node_index == -1) {
    return output_board;
  }

  vector<Graph::Node *> output_path;

  // traverse the from the intersection node to the start node and keep track
  // of our path
  int current_node_index = intersection_node_index;
  while (current_node_index != start_node_index) {
    Graph::Node *node = nodes[current_node_index];
    output_path.push_back(node);
    current_node_index = start_parent[current_node_index];
  }

  // traverse the from the intersection node to the end node and keep track of
  // our path
  current_node_index = intersection_node_index;
  while (current_node_index != end_node_index) {
    Graph::Node *node = nodes[current_node_index];
    output_path.push_back(node);
    current_node_index = end_parent[current_node_index];
  }

  // push the starting and ending node to the final path (optional)
  output_path.push_back(nodes[start_node_index]);
  output_path.push_back(nodes[end_node_index]);

  // update the output board to show the nodes we've visited in our final path
  for (Graph::Node *final_path : output_path) {
    output_board[final_path->row][final_path->col] = kPath;
  }

  // highlight the intersection node in the output board
  size_t intersection_node_row = intersection_node_index / dimension;
  size_t intersection_node_col = intersection_node_index % dimension;
  output_board[intersection_node_row][intersection_node_col] = kIntersectionNode;

  return output_board;
}

} // namespace graph_algorithm