cmake_minimum_required(VERSION 3.7.2)

set(PROJ_NAME 14-overloading-constructors-destructors-move)
project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJ_NAME} 
  main.cpp
)

target_compile_options(${PROJ_NAME} PRIVATE
  -Wall -Wextra -pedantic )