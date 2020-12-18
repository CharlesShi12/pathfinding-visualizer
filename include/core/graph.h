//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_GRAPH_H
#define PATH_ALGORITHM_VISUALIZER_GRAPH_H

#include <vector>
#include <unordered_map>

namespace graph_algorithm {

/**
 * This class stores a graph (represented as an adjacency list).
 */
class Graph {
 public:
  struct Node {
    int row;
    int col;
    std::vector<int> adjacent;
    float distance;

    Node(int row_coordinate, int col_coordinate) {
      row = row_coordinate;
      col = col_coordinate;
      distance = INFINITY;
    }
  };

  /**
   * Creates a Graph object.
   *
   * @param board the board represented as a 2D vector of integers
   */
  Graph(const std::vector<std::vector<int>> &board);

  /**
   * Returns the nodes from the current Graph.
   *
   * @return the nodes from the current Graph
   */
  const std::vector<Node *> &GetNodes();

  /**
   * Returns the board from the current Graph.
   *
   * @return the board from the current Graph
   */
  const std::vector<std::vector<int>> &GetBoard();

  /**
   * Returns the dimension from the current Graph.
   *
   * @return the dimension from the current Graph
   */
  size_t GetDimension();

 private:
  std::vector<std::vector<int>> board_;
  std::vector<Node *> nodes_;
  size_t dimension_;
};

} // namespace graph_algorithm

#endif 