#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace algorithm {

using std::vector;
using std::unordered_map;

class GraphTraversalAlgorithm {

  struct Node {
    int row;
    int col;
    vector<int> adjacent;
    Node(int row_coordinate, int col_coordinate) {
      row = row_coordinate;
      col = col_coordinate;
    }
  };

 private:
  int dimensions_;
  unordered_map<int, Node*> nodes_;
  bool found_destination;
  void DFS(const vector<vector<int>> &board, int node,
                                    size_t end_row, size_t end_col,
                                    vector<bool> &visited_nodes);

 public:
  GraphTraversalAlgorithm(int dimensions);
  void ConvertBoardToGraph(const vector<vector<int>> &board);
  vector<vector<int>> RunBFS(const vector<vector<int>> &board, size_t end_row,
                             size_t end_col);
  vector<vector<int>> RunDFS(const vector<vector<int>> &board, size_t end_row,
                             size_t end_col);
};

};  // namespace algorithm