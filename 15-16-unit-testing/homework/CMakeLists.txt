cmake_minimum_required(VERSION 3.14)

set(PROJ_NAME 15-16-unit-testing)
project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

add_executable(${PROJ_NAME}
  test-list.cpp
  test-array.cpp
)

target_link_libraries(${PROJ_NAME} PRIVATE
  GTest::gtest_main
  GTest::gtest
)

target_compile_options(${PROJ_NAME} PRIVATE
  -Wall -Wextra -pedantic )