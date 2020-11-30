//
// Created by Charles Shi on 11/28/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_A_STAR_H
#define PATH_ALGORITHM_VISUALIZER_A_STAR_H

#include "graph.h"
#include <queue>

namespace graph_algorithm {

/**
 * This class runs the A* Search Algorithm.
 */
class AStar {
 private:
  Graph *board_graph_;

  /**
   * Calculates Euclidean distance between two points.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   */
  double Distance(int start_row, int start_col, int end_row, int end_col);

 public:
  /**
   * Creates a AStar object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  AStar(Graph *board_graph);

  /**
   * Runs the A* Search Algorithm.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   */
  vector<vector<int>> RunAStar(int end_row, int end_col);
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_A_STAR_H
