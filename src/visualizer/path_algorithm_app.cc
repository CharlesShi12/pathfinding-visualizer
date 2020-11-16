#include <visualizer/path_algorithm_app.h>

namespace algorithm {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(206, 235, 251);
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      "Press Delete to clear the sketchpad. Press 1 to run BFS. Press 2 to run DPS.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_1:
      sketchpad_.RunGraphTraversalAlgorithm(true);
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_2:
      sketchpad_.RunGraphTraversalAlgorithm(false);
      sketchpad_.Draw();
      break;

    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      break;
  }
}

}  // namespace visualizer

}  // namespace algorithm
