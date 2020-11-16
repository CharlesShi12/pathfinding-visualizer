#include <visualizer/sketchpad.h>
#include <core/bfs.h>
#include <core/dfs.h>

namespace algorithm {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      brush_radius_(brush_radius) {
  current_board_ = vector<vector<int>>(num_pixels_per_side_,
                                       vector<int>(num_pixels_per_side_, 0));
}

void Sketchpad::Draw() const {
  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      if (current_board_[row][col] == 1) {
        ci::gl::color(ci::Color("black"));

      } else if (current_board_[row][col] == 2) {
        ci::gl::color(ci::Color("gray"));

      } else if (current_board_[row][col] == 3) {
        ci::gl::color(ci::Color("blue"));

      } else {
        ci::gl::color(ci::Color("white"));
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

      if (glm::distance(brush_sketchpad_coords, pixel_center) <=
          brush_radius_) {
        current_board_[row][col] = 1;
      }
    }
  }
}

void Sketchpad::Clear() {
  current_board_ = vector<vector<int>>(num_pixels_per_side_,
                                     vector<int>(num_pixels_per_side_, 0));
}

void Sketchpad::RunGraphTraversalAlgorithm(bool isBFS) {
  size_t start_row = 0;
  size_t start_col = 0;

  size_t end_row = std::rand() % (num_pixels_per_side_ - 1) + 1;
  size_t end_col = std::rand() % (num_pixels_per_side_ - 1) + 1;

  while (current_board_[end_row][end_col] == 1) {
    end_row = std::rand() % (num_pixels_per_side_ - 1) + 1;
    end_col = std::rand() % (num_pixels_per_side_ - 1) + 1;
  }

  Graph* board_graph = new Graph(current_board_);

  if (isBFS) {
    BFS* bfs_algorithm = new BFS(board_graph);
    current_board_ = bfs_algorithm->RunBFS(end_row, end_col);

  } else {
    DFS* dfs_algorithm = new DFS(board_graph);
    current_board_ = dfs_algorithm->RunDFS(end_row, end_col);
  }

  current_board_[start_row][start_col] = 3;
  current_board_[end_row][end_col] = 3;
}

}  // namespace visualizer

}  // namespace algorithm
