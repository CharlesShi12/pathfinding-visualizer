//
// Created by Charles Shi on 12/4/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
#define PATH_ALGORITHM_VISUALIZER_PATHFINDER_H

#include "graph.h"

namespace graph_algorithm {

class Pathfinder {

 protected:
  Graph *board_graph_;
//  vector<vector<int>>

 public:
  Pathfinder(Graph *board_graph) {
    board_graph_ = board_graph;
  }
  virtual vector<vector<int>> Find(size_t end_row, size_t end_col) = 0;
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
