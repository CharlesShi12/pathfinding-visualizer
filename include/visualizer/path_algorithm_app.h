#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace graph_algorithm {

namespace visualizer {

using graph_algorithm::visualizer::Sketchpad;

/**
 * Allows a user to draw a terrain on a sketchpad and visualize a pathfinding
 * algorithm.
 */
class PathVisualizerApp : public ci::app::App {
 public:
  PathVisualizerApp();
  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  static constexpr double kWindowSize = 600;
  static constexpr double kMargin = 75;
  static constexpr size_t kImageDimension = 20;

 private:
  Sketchpad sketchpad_;
  size_t shortest_path_node_count_;
  size_t traversed_node_count_;
};

}  // namespace visualizer

}  // namespace graph_algorithm
