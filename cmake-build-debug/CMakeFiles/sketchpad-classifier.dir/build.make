# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sketchpad-classifier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sketchpad-classifier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sketchpad-classifier.dir/flags.make

Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns: /Users/charlesshi/Downloads/Cinder/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/charlesshi/Downloads/Cinder/samples/data/CinderApp.icns Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/apps/cinder_app_main.cc

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/apps/cinder_app_main.cc > CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.i

CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/apps/cinder_app_main.cc -o CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o: ../src/core/bfs.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bfs.cc

CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bfs.cc > CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bfs.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o: ../src/core/dfs.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/dfs.cc

CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/dfs.cc > CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/dfs.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o: ../src/core/graph.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/graph.cc

CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/graph.cc > CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/graph.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o: ../src/core/a_star.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/a_star.cc

CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/a_star.cc > CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/a_star.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o: ../src/core/bidirectional_bfs.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bidirectional_bfs.cc

CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bidirectional_bfs.cc > CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/bidirectional_bfs.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.s

CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o: ../src/core/pathfinder.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/pathfinder.cc

CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/pathfinder.cc > CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.i

CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/core/pathfinder.cc -o CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o: ../src/visualizer/path_algorithm_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/path_algorithm_app.cc

CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/path_algorithm_app.cc > CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/path_algorithm_app.cc -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.s

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o: CMakeFiles/sketchpad-classifier.dir/flags.make
CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o: ../src/visualizer/sketchpad.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o -c /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/sketchpad.cc

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/sketchpad.cc > CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.i

CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/src/visualizer/sketchpad.cc -o CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.s

# Object files for target sketchpad-classifier
sketchpad__classifier_OBJECTS = \
"CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o" \
"CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o"

# External object files for target sketchpad-classifier
sketchpad__classifier_EXTERNAL_OBJECTS =

Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/apps/cinder_app_main.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/bfs.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/dfs.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/graph.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/a_star.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/bidirectional_bfs.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/core/pathfinder.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/path_algorithm_app.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/src/visualizer/sketchpad.cc.o
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/build.make
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/charlesshi/Downloads/Cinder/lib/macosx/Debug/libcinder.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/charlesshi/Downloads/Cinder/lib/macosx/libboost_system.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: /Users/charlesshi/Downloads/Cinder/lib/macosx/libboost_filesystem.a
Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier: CMakeFiles/sketchpad-classifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sketchpad-classifier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sketchpad-classifier.dir/build: Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/MacOS/sketchpad-classifier
CMakeFiles/sketchpad-classifier.dir/build: Debug/sketchpad-classifier/sketchpad-classifier.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/sketchpad-classifier.dir/build

CMakeFiles/sketchpad-classifier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sketchpad-classifier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sketchpad-classifier.dir/clean

CMakeFiles/sketchpad-classifier.dir/depend:
	cd /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46 /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46 /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug /Users/charlesshi/Downloads/Cinder/my-projects/final-project-CharlesShi46/cmake-build-debug/CMakeFiles/sketchpad-classifier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sketchpad-classifier.dir/depend

