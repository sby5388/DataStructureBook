#《数据结构（第2版）》--高等教育出版史-陈越主编
cmake_minimum_required(VERSION 3.14)
project(DataStructureBook C)

set(CMAKE_C_STANDARD 99)


add_executable(DataStructureBook main.c)


add_subdirectory(chap3)
add_subdirectory(chap4)