#include <visualizer/path_algorithm_app.h>

using graph_algorithm::visualizer::PathVisualizerApp;

void prepareSettings(PathVisualizerApp1::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PathVisualizerApp, ci::app::RendererGl, prepareSettings);
