//
// Created by Charles Shi on 11/15/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BFS_H
#include <vector>

using std::vector;

class BFS {
 private:
  vector<vector<int>> board_;
  size_t dimension_;

 public:
  BFS(const vector<vector<int>> &board);
  vector<vector<int>> RunBFS(size_t end_row, size_t end_col);

};


#endif //PATH_ALGORITHM_VISUALIZER_BFS_H
