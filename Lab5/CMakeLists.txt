#cmake_minimum_required(VERSION 3.10)
project(matrix)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "-fsanitize=address  -fsanitize=leak -g")
#set(CMAKE_C_FLAGS "-fsanitize=address  -fsanitize=leak -g")
#set(CMAKE_EXE_LINKER_FLAGS "-fsanitize=address  -fsanitize=leak")
#set(CMAKE_MODULE_LINKER_FLAGS "-fsanitize=address  -fsanitize=leak")

set(SOURCE_FILES
        complex.cc
        complex.h
        matrix.cc
        matrix.h
        )

add_executable(matrix
        ${SOURCE_FILES}
        main.cc
        )
