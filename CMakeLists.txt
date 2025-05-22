cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(FantasyBT VERSION 0.1
                  DESCRIPTION "Fantasy sports roster strategy backtester"
                  LANGUAGES CXX)
# 
include(cmake/CPM.cmake)

add_executable(fbt "src/main.cpp")
file(GLOB_RECURSE SRC "src/*.cpp" EXCLUDE "src/main.cpp")

file(GLOB_RECURSE TEST_SRC "test/*.cpp")
add_executable(test ${TEST_SRC})


CPMAddPackage(
  NAME magic_enum
  GITHUB_REPOSITORY Neargye/magic_enum
  GIT_TAG v0.9.7
)

find_package(fmt CONFIG REQUIRED)


target_include_directories(fbt PRIVATE include)
target_include_directories(test PRIVATE include)

target_link_libraries(fbt PRIVATE fmt::fmt magic_enum)
target_link_libraries(test PRIVATE fmt::fmt magic_enum)


# include_directories(include)


# link_libraries(fmt::fmt)
# link_libraries(magic_enum)





