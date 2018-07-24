cmake_minimum_required(VERSION 2.8)

#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJ_NAME myList)

include_directories(Exceptions)
include_directories(tests)

project(${PROJ_NAME})

#set(HEADERS myexception.h exoutofrange.h)
set(SOURCES main.cpp mylist.h) #myexception.cpp exoutofrange.cpp)

add_executable(${PROJ_NAME} ${SOURCES}) #${HEADERS})
add_subdirectory(Exceptions)
add_subdirectory(tests)
target_link_libraries(${PROJ_NAME} Exceptions tests)