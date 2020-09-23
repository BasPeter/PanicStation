# Panic Station: A small game concept for the Udacity C++ ND

This is far from a finished game, but rather a small concept. Since it shows my ability to code using C++ I think it is sufficient as the Capstone project for the C++ NanoDegree

<img src="PanicStation.gif"/>

In this game you have to build a trainline from the bottom of an island to the top.
This trainline consist of nodes. Once you reach the goal the program closes and you see the cost of your trainline.

Building a node costs money (of course), the amount of money is based on the height of the node (is it on a mountain or in a hill), the distance from the last node and the difference in height between those two.



## Dependencies for Running Locally

* SDL2
* SDL2 TTF
* SDL2 Images

## Basic Build Instructions
This project was written using Xcode

Go to PanicStation Folder

1. mkdir build
2. cd build/
3. cmake ..
4. make
