cmake_minimum_required(VERSION 2.8)

project(tests)

set(SOURCE_LIB myString.cpp)
set(HEADER_LIB myString.h)

add_library(tests STATIC ${SOURCE_LIB} ${HEADER_LIB})