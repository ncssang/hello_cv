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
add_executable(lowest_common_multiple src/lowest_common_multiple.cpp)
add_executable(reduction_of_a_fraction src/reduction_of_a_fraction.cpp)
add_executable(rotate_point_around_origin src/rotate_point_around_origin src/geometry.cpp)
add_executable(line_is_symmetrical_through_the_line src/line_is_symmetrical_through_the_line.cpp src/geometry.cpp)
add_executable(intersection_of_bisector src/intersection_of_bisector.cpp src/geometry.cpp)
add_executable(binary_search src/binary_search.cpp)
add_executable(backtracking src/backtracking.cpp)
add_executable(sum_square src/sum_square.cpp)
add_executable(multiplication_scalar src/multiplication_scalar.cpp)
add_executable(student_score src/student_score.cpp)
add_executable(product src/product.cpp)
add_executable(random_frequency src/random_frequency.cpp)
add_executable(exponential src/exponential.cpp)
add_executable(hanoitower src/hanoitower.cpp)
add_executable(knight_s_tour src/knight_s_tour.cpp)
add_executable(workes src/workes.cpp)
add_executable(matrix src/matrix.cpp)
add_executable(cubic_equation src/cubic_equation.cpp)



## Specify libraries to link a library or executable target against
target_link_libraries(hello_cv ${OpenCV_LIBS})