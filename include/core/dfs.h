//
// Created by Charles Shi on 11/16/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_DFS_H
#define PATH_ALGORITHM_VISUALIZER_DFS_H

#include <vector>
#include "graph.h"
#include "pathfinder.h"

namespace graph_algorithm {

using std::vector;

/**
 * This class runs the Depth First Search.
 */
class DFS : public Pathfinder {
 private:
  /**
   * Recursive helper method that helps run the Depth First Search algorithm.
   *
   * @param current_node_index the index of the current node that is being visited
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   * @param visited_nodes a vector that stores the nodes that this algorithm
   * has already visited
   */
  bool RecursiveDFS(size_t current_node_index, size_t end_row, size_t end_col,
                         vector<bool> &visited_nodes, vector<Graph::Node*> &path);

 public:
  /**
   * Creates a DFS object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  DFS(Graph *board_graph) : Pathfinder(board_graph) {}

  /**
   * Runs the Depth First Search.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   */
  vector<vector<int>> Find(size_t end_row, size_t end_col);
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_DFS_H