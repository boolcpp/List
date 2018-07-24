cmake_minimum_required(VERSION 2.8)

project(Exceptions)

set(SOURCE_LIB myexception.cpp exoutofrange.cpp)
set(HEADER_LIB myexception.h exoutofrange.h)

add_library(Exceptions STATIC ${SOURCE_LIB} ${HEADER_LIB})