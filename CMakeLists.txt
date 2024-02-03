# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

set (PROJECT_NAME asm-playground)
enable_language(ASM_MASM)
project(${PROJECT_NAME} LANGUAGES CXX ASM)
set(CMAKE_CXX_STANDARD 20)

file (GLOB SOURCES
        code/main.cpp
        code/*.asm
    )

file (GLOB HEADERS
        code/dummy/*.h
    )

set (INCLUDE_DIRS
    "code/dummy"
    "code/")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_source_files_properties(code/func.asm PROPERTIES 
    LANGUAGE ASM_MASM 
    COMPILE_FLAGS "/Zi")
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
source_group("Header Files\\dummy" FILES code/dummy/cdummy.h)
#source_group("Source Files\\dummy" FILES code/dummy/cdummy.c)
source_group("Source Files\\asm" FILES code/func.asm)
