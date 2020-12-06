//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BFS_H

#include "graph.h"
#include "pathfinder.h"
#include <vector>

namespace graph_algorithm {

/**
 * This class runs the Breadth First Search.
 */
class BFS: public Pathfinder {
 public:
  /**
   * Creates a BFS object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  BFS(Graph *board_graph) : Pathfinder(board_graph) {}

  /**
   * Runs the Breadth First Search.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   * @retun the board after running the Breadth First Search
   */
  std::vector<std::vector<int>> Find(size_t end_row, size_t end_col);
};

} // namespace algorithm

#endif //PATH_ALGORITHM_VISUALIZER_BFS_H