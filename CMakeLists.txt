cmake_minimum_required(VERSION 3.18)

project(ProdSysExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)