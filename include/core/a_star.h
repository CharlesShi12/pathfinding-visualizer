//
// Created by Charles Shi on 11/28/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_A_STAR_H
#define PATH_ALGORITHM_VISUALIZER_A_STAR_H

#include "graph.h"
#include <queue>

namespace graph_algorithm {

class AStar {
 private:
  Graph *board_graph_;
  double Distance(int start_row, int start_col, int end_row, int end_col);

 public:
  AStar(Graph *board_graph);
  vector<vector<int>> RunAStar(int end_row, int end_col);
};

}

#endif //PATH_ALGORITHM_VISUALIZER_A_STAR_H
