cmake_minimum_required(VERSION 3.4)

project(hello_world)

## Compile as C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Compile with the highest warning level
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

## System dependencies
find_package(OpenCV REQUIRED)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(${CMAKE_SOURCE_DIR}/include)

## Declare a C++ executable
add_executable(hello_cv src/hello_cv.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(hello_cv ${OpenCV_LIBS})
