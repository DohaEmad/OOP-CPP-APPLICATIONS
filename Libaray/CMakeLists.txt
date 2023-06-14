cmake_minimum_required(VERSION 3.26)
project(Libaray)

set(CMAKE_CXX_STANDARD 14)

add_executable(Libaray main.cpp User.cpp User.h Book.cpp Book.h UserList.cpp UserList.h BookList.cpp BookList.h)
