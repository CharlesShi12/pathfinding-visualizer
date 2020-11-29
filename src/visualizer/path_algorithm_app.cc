#include <visualizer/path_algorithm_app.h>

namespace graph_algorithm {

namespace visualizer {

PathVisualizerApp::PathVisualizerApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void PathVisualizerApp::draw() {
  ci::Color8u background_color(206, 235, 251);
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      "Press Delete to clear, 1 to run BFS, 2 to run DFS, and 3 to run A*.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));
}

void PathVisualizerApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void PathVisualizerApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void PathVisualizerApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_1:
      sketchpad_.RunGraphTraversalAlgorithm("BFS");
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_2:
      sketchpad_.RunGraphTraversalAlgorithm("DFS");
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_3:
      sketchpad_.RunGraphTraversalAlgorithm("AStar");
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      break;
  }
}

}  // namespace visualizer

}  // namespace graph_algorithm
