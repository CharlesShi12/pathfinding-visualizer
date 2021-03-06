## Pathfinding Visualizer

![Pathfinding Visualizer Example #1](https://github.com/uiuc-fa20-cs126/final-project-CharlesShi46/blob/week2/example_images/example%231.png)

![Pathfinding Visualizer Example #2](https://github.com/uiuc-fa20-cs126/final-project-CharlesShi46/blob/week2/example_images/example%232.png)

![Pathfinding Visualizer Example #3](https://github.com/uiuc-fa20-cs126/final-project-CharlesShi46/blob/week2/example_images/example%233.png)

Project Demonstration here: https://youtu.be/tj44CikxLNg

## About this project

The pathfinding visualizer project is a Cinder application that displays a sketchpad where users can clear and draw terrains and mazes for the pathfinding algorithms to solve and traverse. The pathfinding algorithms that we visualize are Breadth-First Search, Depth-First Search, A*, and Bi-directional Breadth-First Search with the nodes traversed and final paths of each algorithm highlighted with different colors. The Breadth-First Search, A*, and Bi-directional Breadth-First Search produce a path that is the shortest from the start destination to the end destination. Moreover, users can analyze the statistics about each pathfinding algorithm and compare them to each other (ex. the total length of the final path, how many nodes did this specific algorithm traverse, etc). The entire project was written in C++. 

## How to build it

If you are using Ubuntu, follow the instructions here: https://www.libcinder.org/docs/guides/linux-notes/ubuntu.html.

If you haven't installed CLion, then install it from https://www.jetbrains.com/clion/download. 

First, download Cinder from https://libcinder.org/download and put the downloaded item into a folder. 

Next, name the folder ~/Cinder and open the ~/Cinder folder in CLion. Then, click the green build button in CLion. 

Create a project directory called my-projects in the ~/Cinder folder and clone this repository in the my-projects directory. 

Open the cloned repository and run the program. 

## How to use it

Key | Action
------------ | -------------
1 | Run Breadth-First Search
2 | Run Depth-First Search
3 | Run A Star Search
4 | Run Bidirectional Breadth-First Search
Mouse Click | Draw a wall on the sketchpad
Delete | Clear the sketchpad

## Node Legend

Color | Node Representation
------------ | -------------
White | Unvisited node, but Reachable Node
Gray | Visited Node Starting at Start Location
Light-Gray | Visited Node Starting at End Location (For Bidirectional BFS)
Black | Unreachable Node
Green | Intersection Node (For Bidirectional BFS)
Blue | Start and End Nodes
Red | Final Output Path Node
