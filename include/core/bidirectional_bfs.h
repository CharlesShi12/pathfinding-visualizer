//
// Created by Charles Shi on 12/3/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H

#include "graph.h"
#include "pathfinder.h"
#include <queue>

namespace graph_algorithm {

/**
 * This class runs the Bi-directional Breadth First Search.
 */
class BidirectionalBFS: public Pathfinder {
 private:
  /**
   * Runs the BFS algorithm for one node (or step).
   *
   * @param next_nodes the next nodes that we need to visit
   * @param visited_nodes the nodes we have already visited
   * @param parent the parent node of a specific node
   */
  void BFS(std::queue<size_t> &next_nodes, std::vector<bool> &visited_nodes,
           std::vector<size_t> &parent);

  /**
   * Finds the node that the start and end breadth first searches collided with,
   * if there is a node.
   *
   * @param start_visited_nodes the nodes that the start BFS visited
   * @param end_visited_nodes the nodes that the end BFS visited
   * @return the id of the collided node or -1 if there is no collided node
   */
  int CollisionNode(const std::vector<bool> &start_visited_nodes,
                    const std::vector<bool> &end_visited_nodes);

 public:
  /**
   * Creates a BidirectionalBFS object.
   *
   * @param board_graph the board represented as a Graph object (or also known
   * as an adjacency matrix)
   */
  BidirectionalBFS(Graph *board_graph) : Pathfinder(board_graph) {}

  /**
   * Runs the Bidirectional Breadth First Search.
   *
   * @param end_row the row coordinate of the end destination
   * @param end_col the column coordinate of the end destination
   * @return the board after running the bidirectional Breadth First Search
   */
  std::vector<std::vector<int>> Find(size_t end_row, size_t end_col);
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H
