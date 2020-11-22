//
// Created by Charles Shi on 11/16/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_DFS_H
#define PATH_ALGORITHM_VISUALIZER_DFS_H

#include <vector>
#include "graph.h"

namespace graph_algorithm {

using std::vector;

/**
 * This class runs the Depth First Search.
 */
class DFS {
 private:
  Graph *board_graph_;
  bool found_destination_;
  vector<Graph::Node *> path_;

  /**
   * Recursive helper method that helps run the Depth First Search algorithm.
   *
   * @param node the current node that is being visited
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   * @param visited_nodes a vector that stores the nodes that this algorithm
   * has already visited
   */
  void RecursiveDFS(size_t node_index, size_t end_row, size_t end_col,
                         vector<bool> &visited_nodes);

 public:
  /**
   * Creates a DFS object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  DFS(Graph *board_graph);

  /**
   * Runs the Depth First Search.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   */
  vector<vector<int>> RunDFS(size_t end_row, size_t end_col);
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_DFS_H