cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME myList)
project(${PROJ_NAME})

set(SOURCES main.cpp mylist.h)
#set(SOURCE_LIB mylist.cpp)

#add_library(Mylist STATIC ${SOURCE_LIB})

add_executable(${PROJ_NAME} ${SOURCES})

#target_link_libraries(executableFile Mylist)
