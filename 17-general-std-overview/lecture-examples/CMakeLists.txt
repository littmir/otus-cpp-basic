cmake_minimum_required(VERSION 3.12)

project(17.STL)

add_executable(string                          string.cpp)
add_executable(containers                      containers.cpp)
add_executable(string_file_extension           string_file_extension.cpp)
add_executable(string_view_file_extension      string_view_file_extension.cpp)
add_executable(file_io                         file_io.cpp)
add_executable(string_modify                   string_modify.cpp)
add_executable(filesystem                      filesystem.cpp)
add_executable(chrono                          chrono.cpp)
add_executable(limits                          limits.cpp)
add_executable(regex                           regex.cpp)


set_target_properties(
    string 
    string_file_extension
    string_view_file_extension
    file_io
    string_modify
    filesystem
    chrono
    limits
    regex
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
