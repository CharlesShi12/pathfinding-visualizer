//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_GRAPH_H
#define PATH_ALGORITHM_VISUALIZER_GRAPH_H

#include <vector>
#include <unordered_map>

namespace graph_algorithm {

using std::vector;

/**
 * This class stores a graph.
 */
class Graph {
 public:
  struct Node {
    int row;
    int col;
    vector<int> adjacent;
    float distance = INFINITY;

    Node(int row_coordinate, int col_coordinate) {
      row = row_coordinate;
      col = col_coordinate;
    }
  };

  /**
   * Creates a Graph object.
   *
   * @param board the board represented as a 2D vector of integers
   */
  Graph(const vector<vector<int>> &board);

  /**
   * Returns the nodes from the current Graph.
   *
   * @return the nodes from the current Graph
   */
  const vector<Node *> &GetNodes();

  /**
   * Returns the board from the current Graph.
   *
   * @return the board from the current Graph
   */
  const vector<vector<int>> &GetBoard();

  /**
   * Returns the dimension from the current Graph.
   *
   * @return the dimension from the current Graph
   */
  size_t GetDimension();

 private:
  size_t dimension_;
  vector<vector<int>> board_;
  vector<Node *> nodes_;
};

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_GRAPH_H