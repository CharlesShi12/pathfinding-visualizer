#include <visualizer/path_algorithm_app.h>

namespace graph_algorithm {

namespace visualizer {

using std::pair;

PathVisualizerApp::PathVisualizerApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  traversed_node_count_ = 0;
  shortest_path_node_count_ = 0;
}

void PathVisualizerApp::draw() {
  ci::Color8u background_color(206, 235, 251);
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      "Press Delete to clear, 1 to run BFS, 2 to run DFS, 3 to run A*, and 4 "
      "to run Bidirectional BFS.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

  ci::gl::drawStringCentered(
      "Number of nodes traversed for the algorithm's path: " +
      std::to_string(shortest_path_node_count_),
      glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 3),
      ci::Color("black"));

  ci::gl::drawStringCentered(
      "Total number of nodes traversed: " + std::to_string(traversed_node_count_),
      glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 1.5),
      ci::Color("black"));
}

void PathVisualizerApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void PathVisualizerApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void PathVisualizerApp::keyDown(ci::app::KeyEvent event) {
  pair<size_t, size_t> node_counts = {0, 0};

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

    case ci::app::KeyEvent::KEY_4:
      sketchpad_.RunGraphTraversalAlgorithm("BidirectionalBFS");
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      node_counts = {0, 0};
      traversed_node_count_ = 0;
      shortest_path_node_count_ = 0;
      sketchpad_.Draw();
      break;
  }

  // if the user visualized an algorithm, analyze the algorithm's final path and
  // traversed nodes
  if (event.getCode() == ci::app::KeyEvent::KEY_1 ||
      event.getCode() == ci::app::KeyEvent::KEY_2 ||
      event.getCode() == ci::app::KeyEvent::KEY_3 ||
      event.getCode() == ci::app::KeyEvent::KEY_4) {
    node_counts = sketchpad_.CountShortestPathAndTraversedNodes();
    shortest_path_node_count_ = node_counts.first;
    traversed_node_count_ = node_counts.second;
  }
}

}  // namespace visualizer

}  // namespace graph_algorithm
