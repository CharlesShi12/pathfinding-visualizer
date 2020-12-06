#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace graph_algorithm {

namespace visualizer {

using graph_algorithm::visualizer::Sketchpad;

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class PathVisualizerApp : public ci::app::App {
 public:
  PathVisualizerApp();
  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 600;
  const double kMargin = 75;
  const size_t kImageDimension = 20;

 private:
  Sketchpad sketchpad_;
};

}  // namespace visualizer

}  // namespace graph_algorithm
