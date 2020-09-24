cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PanicStation)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL_TTF_INCLUDE_DIRS})

add_executable(PanicStation main.cpp Game/Game.cpp Controller/Controller.cpp Renderer/Renderer.cpp GameObjects/Node.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PanicStation ${SDL2_LIBRARIES})
