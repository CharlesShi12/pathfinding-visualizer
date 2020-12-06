//
// Created by Charles Shi on 12/3/20.
//

#ifndef PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H
#define PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H

#include "graph.h"
#include "pathfinder.h"
#include <vector>
#include <queue>

namespace graph_algorithm {

using std::queue;

/**
 * This class runs the Bi-directional Breadth First Search.
 */
class BidirectionalBFS : public Pathfinder {
   private:
  void BFS(queue<size_t> &next_nodes, vector<bool> &visited_nodes, vector<size_t> &path);
  int IsCollided(vector<bool> start_visited_nodes, vector<bool> end_visited_nodes);

   public:
    /**
     * Creates a BidirectionalBFS object.
     *
     * @param board_graph the board represented as a Graph object (or also known
     * as an adjacency matrix)
     */
    BidirectionalBFS(Graph *board_graph) : Pathfinder(board_graph) {}

    /**
     * Runs the Bidirectional Breadth First Search and outputs the shortest path
     * from the start destination to end destination.
     *
     * @param end_row the row coordinate of the end destination
     * @param end_col the column coordinate of the end destination
     */
    vector<vector<int>> Find(size_t end_row, size_t end_col);
  };

} // namespace graph_algorithm

#endif //PATH_ALGORITHM_VISUALIZER_BIDIRECTIONAL_BFS_H
