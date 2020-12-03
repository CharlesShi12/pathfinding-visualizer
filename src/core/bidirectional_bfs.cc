//
// Created by Charles Shi on 12/3/20.
//

#include "core/bidirectional_bfs.h"
#include <core/graph.h>
#include <visualizer/sketchpad.h>
#include <queue>

namespace graph_algorithm {

using std::queue;

BidirectionalBFS::BidirectionalBFS(Graph *board_graph) {
  board_graph_ = board_graph;
}

void BidirectionalBFS::BFS(queue<size_t> &next_nodes, vector<bool> &visited_nodes) {
  Graph::Node *current_node = board_graph_->GetNodes()[next_nodes.front()];
  visited_nodes[next_nodes.front()] = true;
  next_nodes.pop();

  // push the adjacent nodes of the current node to the queue
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

} // namespace graph_algorithm
