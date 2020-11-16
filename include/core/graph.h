//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_GRAPH_H
#define PATH_ALGORITHM_VISUALIZER_GRAPH_H

#include <vector>
#include <unordered_map>

namespace graph_algorithm {
using std::vector;
using std::unordered_map;

class Graph {
 public:
  struct Node {
    int row;
    int col;
    vector<int> adjacent;
    Node(int row_coordinate, int col_coordinate) {
      row = row_coordinate;
      col = col_coordinate;
    }
  };

  Graph(const vector<vector<int>> &board);
  const unordered_map<int, Node *> &GetNodes();
  const vector<vector<int>> &GetBoard();
  size_t GetDimension();

 private:
  size_t dimension_;
  vector<vector<int>> board_;
  unordered_map<int, Node *> nodes_;
};

}
#endif //PATH_ALGORITHM_VISUALIZER_GRAPH_H