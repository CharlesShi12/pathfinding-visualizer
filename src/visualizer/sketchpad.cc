#include <visualizer/sketchpad.h>
#include <core/bfs.h>
#include <core/dfs.h>
#include <random>
#include <core/a_star.h>

namespace graph_algorithm {

namespace visualizer {

using glm::vec2;
using std::string;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      brush_radius_(brush_radius) {
  current_board_ = vector<vector<int>>(num_pixels_per_side_,
                                       vector<int>(num_pixels_per_side_, 0));
  // generating a random number from a certain interval
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type>
      dist(1, num_pixels_per_side_ - 1);

  start_row_ = 0;
  start_col_ = 0;
  end_row_ = dist(rng);
  end_col_ = dist(rng);
  current_board_[start_row_][start_col_] = kStartAndEndNode;
  current_board_[end_row_][end_col_] = kStartAndEndNode;
}

void Sketchpad::Draw() const {
  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      if (current_board_[row][col] == kWall) {
        ci::gl::color(ci::Color("black"));

      } else if (current_board_[row][col] == kTraversedNodes) {
        ci::gl::color(ci::Color8u(108, 116, 118));

      } else if (current_board_[row][col] == kStartAndEndNode) {
        ci::gl::color(ci::Color8u(21, 52, 80));

      } else if (current_board_[row][col] == kPath) {
        ci::gl::color(ci::Color8u(127, 23, 31));

      } else {
        ci::gl::color(ci::Color8u(240, 236, 235));
      }

      vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                    row * pixel_side_length_);

      vec2 pixel_bottom_right =
          pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
      ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

      ci::gl::drawSolidRect(pixel_bounding_box);

      ci::gl::color(ci::Color("black"));
      ci::gl::drawStrokedRect(pixel_bounding_box);
    }
  }
}

void Sketchpad::HandleBrush(const vec2& brush_screen_coords) {
  vec2 brush_sketchpad_coords =
      (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      vec2 pixel_center = {col + 0.5, row + 0.5};

      // make sure the user is not drawing over the start and end positions
      if (glm::distance(brush_sketchpad_coords, pixel_center) <=
          brush_radius_ && current_board_[row][col] != kStartAndEndNode) {
        current_board_[row][col] = kWall;
      }
    }
  }
}

void Sketchpad::Clear() {
  current_board_ = vector<vector<int>>(num_pixels_per_side_,
                                       vector<int>(num_pixels_per_side_, 0));
  current_board_[start_row_][start_col_] = kStartAndEndNode;
  current_board_[end_row_][end_col_] = kStartAndEndNode;
}

void Sketchpad::RunGraphTraversalAlgorithm(const string &algorithm) {
  Graph board_graph(current_board_);

  if (algorithm == "BFS") {
    BFS bfs_algorithm(&board_graph);
    current_board_ = bfs_algorithm.RunBFS(end_row_, end_col_);

  } else if (algorithm == "DFS"){
    DFS dfs_algorithm(&board_graph);
    current_board_ = dfs_algorithm.RunDFS(end_row_, end_col_);

  } else {
    AStar a_star_algorithm(&board_graph);
    current_board_ = a_star_algorithm.RunAStar(end_row_, end_col_);
  }

  // mark the start and end nodes for the user to see
  current_board_[start_row_][start_col_] = kStartAndEndNode;
  current_board_[end_row_][end_col_] = kStartAndEndNode;
}

}  // namespace visualizer

}  // namespace graph_algorithm
