cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(FantasyBT VERSION 0.1
                  DESCRIPTION "Fantasy sports roster strategy backtester"
                  LANGUAGES CXX)
# 
include(cmake/CPM.cmake)
                  
add_executable(fbt src/main.cpp)

file(GLOB_RECURSE TEST_SRC test/*.cpp)
add_executable(test TEST_SRC)

include_directories(include)
CPMAddPackage(
  NAME magic_enum
  GITHUB_REPOSITORY Neargye/magic_enum
  GIT_TAG v0.9.7
)

link_libraries(magic_enum)





