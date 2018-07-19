cmake_minimum_required(VERSION 2.8)

#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJ_NAME myList)
project(${PROJ_NAME})

set(HEADERS myexception.h exoutofrange.h)
set(SOURCES main.cpp mylist.h myexception.cpp exoutofrange.cpp)

add_executable(${PROJ_NAME} ${SOURCES} ${HEADERS})
