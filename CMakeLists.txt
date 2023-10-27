cmake_minimum_required(VERSION 3.24)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
project(hello LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/googletest/googletest/include)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/googletest)

add_executable(main main.cpp ${srcs})

target_link_libraries(
  main
  gtest_main
)

enable_testing()