//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BFS_H

#include <vector>
#include "graph.h"
#include "pathfinder.h"

namespace graph_algorithm {

using std::vector;

/**
 * This class runs the Breadth First Search.
 */
class BFS : public Pathfinder {
 public:
  /**
   * Creates a BFS object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  BFS(Graph *board_graph) : Pathfinder(board_graph) {}

  /**
   * Runs the Breadth First Search and outputs the shortest path from the start
   * destination to end destination.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   */
  vector<vector<int>> Find(size_t end_row, size_t end_col);
};

} // namespace algorithm

#endif //PATH_ALGORITHM_VISUALIZER_BFS_H