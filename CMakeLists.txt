cmake_minimum_required(VERSION 2.8)

project(ListSrc)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB mylist.cpp)

add_library(Mylist STATIC ${SOURCE_LIB})

add_executable(executableFile ${SOURCE_EXE})

target_link_libraries(executableFile Mylist)
