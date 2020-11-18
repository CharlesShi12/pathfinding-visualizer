//
// Created by Charles Shi on 11/15/20.
//

#include <core/graph.h>
#include <visualizer/sketchpad.h>
#include <core/bfs.h>
#include <queue>

namespace graph_algorithm {

namespace bfs {

BFS::BFS(Graph *board_graph) {
  board_graph_ = board_graph;
}

vector<vector<int>> BFS::RunBFS(size_t end_row, size_t end_col) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  size_t dimension = board_graph_->GetDimension();

  // keep track of the nodes we have already visited
  vector<bool> visited_nodes = vector<bool>(dimension * dimension, false);

  // create a queue of nodes to visit next
  std::queue<size_t> next_nodes;

  // push the first node (starting point) to the queue
  size_t first_node = 0;
  next_nodes.push(first_node);

  while (!next_nodes.empty()) {
    Graph::Node *vertex = board_graph_->GetNodes().at(next_nodes.front());
    visited_nodes[next_nodes.front()] = true;
    next_nodes.pop();

    // check if this node is our final destination
    if (vertex->row == end_row && vertex->col == end_col) {
      break;
    }

    // push the adjacent nodes of the current node to the queue
    for (size_t neighbor : vertex->adjacent) {
      if (!visited_nodes[neighbor]) {
        next_nodes.push(neighbor);
      }
    }
  }

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = board_graph_->GetNodes().at(i);
      output_board[node->row][node->col] = graph_algorithm::kPath;
    }
  }
  return output_board;
}

} // namespace bfs

} // namespace graph_algorithm