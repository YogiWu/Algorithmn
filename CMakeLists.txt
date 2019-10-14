cmake_minimum_required(VERSION 3.14)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(utils)

add_subdirectory(print_combination)
add_subdirectory(number_split)
add_subdirectory(number_multiplication)
add_subdirectory(liner_search)
add_subdirectory(matrix_multipliction)
add_subdirectory(max_length_subseq)
add_subdirectory(optimal_BST)

add_subdirectory(diamond_search)

add_executable(Algorithmn main.cpp)