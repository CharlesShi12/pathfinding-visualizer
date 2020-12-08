//
// Created by Charles Shi on 12/4/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
#define PATH_ALGORITHM_VISUALIZER_PATHFINDER_H

#include "graph.h"
#include <vector>

namespace graph_algorithm {

/**
 * This class is the parent class to multiple pathfinding algorithm child
 * classes and holds the necessary information shared by these child classes.
 */
class Pathfinder {
 protected:
  Graph *board_graph_;

  /**
   * Constructs a board based on the visited nodes and the final path.
   *
   * @param visited_nodes the nodes that were visited by the algorithm
   * @param path the final path that the algorithm took
   * @return the new output board based after applying the inputted information
   */
  std::vector<std::vector<int>> ConstructBoard(
      const std::vector<bool> &visited_nodes,
      const std::vector<Graph::Node *> &path);

 public:
  /**
   * Creates a Pathfinder object.
   *
   * @param board_graph the board represented as a Graph object (or as a
   * adjacency list)
   */
  Pathfinder(Graph *board_graph);

  /**
   * Runs the current algorithm.
   *
   * @param end_row the row coordinate for the end destination
   * @param end_col the column coordinate for the end destination
   * @return the board after running the current algorithm
   */
  virtual std::vector<std::vector<int>> Find(size_t end_row, size_t end_col) = 0;
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_PATHFINDER_H
