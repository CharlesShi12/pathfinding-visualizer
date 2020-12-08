#pragma once

#include "cinder/gl/gl.h"
#include <vector>

namespace graph_algorithm {

using std::vector;
using std::string;

constexpr size_t kWall = 1;
constexpr size_t kTraversedNodes = 2;
constexpr size_t kStartAndEndNode = 3;
constexpr size_t kPath = 4;
constexpr size_t kAlternativeTraversedNodes = 5;
constexpr size_t kIntersectionNode = 6;

namespace visualizer {

/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse and keyboard events.
 */
class Sketchpad {
 public:
  /**
   * Creates a sketchpad.
   * (Note that sketchpad pixels are larger than screen pixels.)
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the sketchpad
   * @param num_pixels_per_side the number of sketchpad pixels in one row/column
   *                            of the sketchpad
   * @param sketchpad_size      the side length of the sketchpad, measured in
   *                            screen pixels
   * @param brush_radius        the maximum distance (measured in sketchpad
   *                            pixels) from the brush that will be shaded
   */
  Sketchpad(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
            double sketchpad_size, double brush_radius = 0.5);

  /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
  void Draw() const;

  /**
   * Shades in the sketchpad pixels whose centers are within brush_radius units
   * of the brush's location. (One unit is equal to the length of one sketchpad
   * pixel.)
   *
   * @param brush_screen_coords the screen coordinates at which the brush is
   * located
   */
  void HandleBrush(const glm::vec2& brush_screen_coords);

  /**
   * Set all of the sketchpad pixels to an unshaded state, aside from the start
   * and end pixels.
   */
  void Clear();

  /**
   * Runs a graph traversal algorithm on the current sketchpad terrain.
   *
   * @param algorithm this string represents whether the user wants BFS, DFS,
   * A*, or Bidirectional BFS
   */
  void RunGraphTraversalAlgorithm(const string &algorithm);

  /**
   * Count the number of nodes that make up the algorithm's path and count the
   * number of the nodes that the algorithm has traversed.
   *
   * @return a pair where the first value represents the number of nodes that
   * make up the algorithm's final path and the second value represents the
   * number of nodes that the algorithm traversed
   */
  std::pair<size_t, size_t> CountPathAndTraversedNodes();

  /**
   * Sets the current board to the inputted board.
   *
   * @param board the board that the current board will be set to
   */
  void SetCurrentBoard(const std::vector<std::vector<int>> &board);

 private:
  vector<vector<int>> current_board_;
  glm::vec2 top_left_corner_;
  size_t num_pixels_per_side_;
  double pixel_side_length_;
  double brush_radius_;
  size_t start_row_;
  size_t start_col_;
  size_t end_row_;
  size_t end_col_;
};

}  // namespace visualizer

}  // namespace graph_algorithm
