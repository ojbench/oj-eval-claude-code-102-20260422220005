cmake_minimum_required(VERSION 3.10)
project(Problem102)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code main.cpp)

# Set compiler flags
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(code PRIVATE -Wall -Wextra -O2)
endif()