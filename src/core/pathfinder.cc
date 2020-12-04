//
// Created by Charles Shi on 12/4/20.
//

#include "core/pathfinder.h"
#include <visualizer/sketchpad.h>

namespace graph_algorithm {

Pathfinder::Pathfinder(Graph *board_graph) {
  board_graph_ = board_graph;
}

vector<vector<int>> Pathfinder::ConstructBoard(const vector<bool> &visited_nodes,
                                               const vector<Graph::Node*> &path) {
  vector<vector<int>> output_board = board_graph_->GetBoard();
  vector<Graph::Node*> nodes = board_graph_->GetNodes();
  size_t dimension = board_graph_->GetDimension();

  // update the output board to show the nodes we've visited from the start to
  // find the end destination
  for (size_t i = 0; i < dimension * dimension; i++) {
    if (visited_nodes[i]) {
      Graph::Node *node = nodes[i];
      output_board[node->row][node->col] = kTraversedNodes;
    }
  }

  // update the output board to show the nodes we've visited in our final
  // path
  for (Graph::Node *final_path : path) {
    output_board[final_path->row][final_path->col] = kPath;
  }

  return output_board;
}

} // namespace graph_algorithm
