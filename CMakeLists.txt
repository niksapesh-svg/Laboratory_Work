cmake_minimum_required(VERSION 3.10)
project(pz1_dynamic_array CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    src/DynamicArray.cpp
    src/main.cpp
)

target_include_directories(main PRIVATE include)

if(MSVC)
    target_compile_options(main PRIVATE /W4)
else()
    target_compile_options(main PRIVATE -Wall -Wextra)
endif()
