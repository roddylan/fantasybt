cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(FantasyBT VERSION 0.1
                  DESCRIPTION "Fantasy sports roster strategy backtester"
                  LANGUAGES CXX)
# 
include(cmake/CPM.cmake)

# cleanup warnings for mac
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unknown-attributes)
endif()


file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
# list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
# add_subdirectory(lib/libpqxx build-pqxx)
file(GLOB_RECURSE TEST_SRC "test/*.cpp")


add_executable(fbt ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${SRC})
add_executable(test ${TEST_SRC} ${SRC})


CPMAddPackage(
  NAME magic_enum
  GITHUB_REPOSITORY Neargye/magic_enum
  GIT_TAG v0.9.7
)

find_package(fmt CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(libpqxx REQUIRED)



target_include_directories(fbt PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(fbt PRIVATE fmt::fmt magic_enum pqxx)
target_link_libraries(test PRIVATE fmt::fmt magic_enum pqxx)


# include_directories(include)


# link_libraries(fmt::fmt)
# link_libraries(magic_enum)





