cmake_minimum_required(VERSION 3.26)
project(Project3_CrashGuard)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project3_CrashGuard src/main.cpp
        src/HashMap.h
        src/RedBlackTree.h
        src/RedBlackTree.cpp
        src/HashMap.cpp)
