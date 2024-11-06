cmake_minimum_required(VERSION 3.28)
project(stf VERSION 0.0.1
                 DESCRIPTION "Sonic Team Formats"
                 LANGUAGES CXX)

add_subdirectory(../simple-reflection simplerfl)
add_subdirectory(../universal-cslib ucsl)

add_library(stf INTERFACE)
target_compile_features(stf INTERFACE cxx_std_20)
target_link_libraries(stf INTERFACE simple-reflection universal-cslib)
add_subdirectory(src)
