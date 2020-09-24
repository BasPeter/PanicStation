# Panic Station: A small game concept for the Udacity C++ ND
## Capstone Option 1 - Video game

This is far from a finished game, but rather a small concept. Since it shows my ability to code using C++ I think it is sufficient as the Capstone project for the C++ NanoDegree

<img src="PanicStation.gif"/>

In this game you have to build a trainline from the bottom of an island to the top.
This trainline consist of nodes. Once you reach the goal the program closes and you see the cost of your trainline.

Building a node costs money (of course), the amount of money is based on the height of the node (is it on a mountain or in a hill), the distance from the last node and the difference in height between those two.

## Files and Classes



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* SDL2_image
  * Instructions van be found [here](http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions
This project was written using Xcode

Go to PanicStation Folder

1. mkdir build
2. cd build/
3. cmake ..
4. make

## Udacity Meeting Specifications

### README
 * README is included
 * Installation instructions for cross platform installation
 * Submitted as markdown
 
 * README describes chosen project
 * README describes file and class structure
 * README indicates rubric points adressed
 
### Compiling and testing
 * The project compiles and runs without errors
 * The project builds using cmake and make
 
### Loops, Functions, IO
 * The projects is structured into classes and functions
 
### OOP
 * The project is organized into classes with attributes and methods
 * All class data members are explicitly specified as public, private or protected
 * All class members that are set to argument values are initialized through member initialization lists.
 * All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
 * Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. 
 
 
