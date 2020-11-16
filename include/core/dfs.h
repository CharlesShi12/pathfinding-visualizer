//
// Created by Charles Shi on 11/16/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_DFS_H
#define PATH_ALGORITHM_VISUALIZER_DFS_H

#include <vector>
#include "graph.h"

namespace graph_algorithm {

namespace dfs {
using std::vector;

class DFS {
 private:
  Graph *board_graph_;
  bool found_destination_;
  void RecursiveDFS(int node,
                    size_t end_row,
                    size_t end_col,
                    vector<bool> &visited_nodes);

 public:
  DFS(Graph *board_graph);
  vector<vector<int>> RunDFS(size_t end_row, size_t end_col);
};

}
}
#endif //PATH_ALGORITHM_VISUALIZER_DFS_H