//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_GRAPH_H
#define PATH_ALGORITHM_VISUALIZER_GRAPH_H
#include <vector>
#include <unordered_map>

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

  Graph(size_t dimension);
  void ConvertBoardToGraph(const vector<vector<int>> &board);
  unordered_map<int, Node*> GetNodes();

 private:
  size_t dimension_;
  unordered_map<int, Node*> nodes_;

};


#endif //PATH_ALGORITHM_VISUALIZER_GRAPH_H
