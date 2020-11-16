//
// Created by Charles Shi on 11/16/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_DFS_H
#define PATH_ALGORITHM_VISUALIZER_DFS_H
#include <vector>
#include "graph.h"

using std::vector;

class DFS {

 private:
  vector<vector<int>> board_;
  size_t dimension_;
  bool found_destination_;
  unordered_map<int, Graph::Node*> nodes_;

  void RecursiveDFS(int node, size_t end_row, size_t end_col, vector<bool> &visited_nodes);

 public:
  DFS(const vector<vector<int>> &board);
  vector<vector<int>> RunDFS(size_t end_row, size_t end_col);

};


#endif //PATH_ALGORITHM_VISUALIZER_DFS_H
