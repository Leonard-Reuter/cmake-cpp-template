cmake_minimum_required(VERSION 3.14)
project(cmake_cpp_template)

include(cmake/GoogleTest.cmake)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(example)
