cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)  # Use C++17

add_executable(MyProject 
    src/main.cpp
    src/lib/ModelTagging.cpp
    src/lib/ModelParser.cpp
)
