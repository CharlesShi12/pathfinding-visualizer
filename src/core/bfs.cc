//
// Created by Charles Shi on 11/15/20.
//

#include <core/graph.h>
#include <core/bfs.h>
#include <queue>

namespace graph_algorithm {

vector<vector<int>> BFS::Find(size_t end_row, size_t end_col) {
  vector<Graph::Node*> nodes = board_graph_->GetNodes();
  size_t dimension = board_graph_->GetDimension();

  // keep track of the nodes we have already visited
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // create a queue of nodes to visit next
  std::queue<size_t> next_nodes;

  // push the first node (starting point) to the queue and set starting distance
  // to 0
  size_t starting_node = 0;
  next_nodes.push(starting_node);
  Graph::Node *start = nodes[starting_node];
  start->distance = 0;

  while (!next_nodes.empty()) {
    Graph::Node *current_node = nodes[next_nodes.front()];
    visited_nodes[next_nodes.front()] = true;
    next_nodes.pop();

    // check if this node is our final destination
    if (current_node->row == end_row && current_node->col == end_col) {
      break;
    }

    // push the adjacent nodes of the current node to the queue
    for (size_t neighbor : current_node->adjacent) {
      if (!visited_nodes[neighbor]) {
        next_nodes.push(neighbor);
        Graph::Node *adjacent = nodes[neighbor];
        adjacent->distance = current_node->distance + 1;
      }
    }
  }

  vector<Graph::Node *> shortest_path;
  Graph::Node *node = nodes[end_row * dimension + end_col];

  // retrace our steps from the end destination until we reach the starting
  // node (row 0, col 0)
  while (node->row != 0 || node->col != 0) {
    shortest_path.push_back(node);

    for (size_t neighbor : node->adjacent) {
      Graph::Node *adjacent = nodes[neighbor];

      if (adjacent->distance != INFINITY &&
          adjacent->distance == node->distance - 1) {
        node = adjacent;
        break;
      }
    }
  }

  // push back the start node (optional)
  shortest_path.push_back(node);

  return ConstructBoard(visited_nodes, shortest_path);
}

} // namespace graph_algorithm