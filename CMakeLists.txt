cmake_minimum_required(VERSION 3.29)
project(templatedlinkedlist)

set(CMAKE_CXX_STANDARD 20)

add_executable(templatedlinkedlist main.cpp
        listtests.h
        memorymanager.cpp)
