cmake_minimum_required(VERSION 2.8.11)

#输出debug信息
set(CMAKE_VERBOSE_MAKEFILE ON)
add_definitions(-std=c++11)
PROJECT(CHATROOM)
ADD_SUBDIRECTORY(write)
ADD_SUBDIRECTORY(read)
ADD_SUBDIRECTORY(proto_lib)