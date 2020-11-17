//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BFS_H

#include <vector>
#include "core/graph.h"

namespace graph_algorithm {

namespace bfs {

using std::vector;

class BFS {
 private:
  Graph *board_graph_;

 public:
  BFS(Graph *board_graph);
  vector<vector<int>> RunBFS(size_t end_row, size_t end_col);
};

} // namespace bfs

} // namespace algorithm

#endif //PATH_ALGORITHM_VISUALIZER_BFS_H