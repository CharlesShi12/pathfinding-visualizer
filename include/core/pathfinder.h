//
// Created by Charles Shi on 12/4/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
#define PATH_ALGORITHM_VISUALIZER_PATHFINDER_H

#include "graph.h"
#include <vector>

namespace graph_algorithm {

class Pathfinder {

 protected:
  Graph *board_graph_;
  std::vector<std::vector<int>> ConstructBoard(
      const std::vector<bool> &visited_nodes,
      const std::vector<Graph::Node *> &path);

 public:
  Pathfinder(Graph *board_graph);
  virtual std::vector<std::vector<int>>
  Find(size_t end_row, size_t end_col) = 0;
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
