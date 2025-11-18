cmake_minimum_required(VERSION 3.23)

project(PulseSTL_Project)

# Require C++23 for nested-namespace-definition and other modern features
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Creating executable for an example of the PulseSTL
add_executable(PulseSTL_Example)

target_sources(PulseSTL_Example
    PRIVATE
        example/main.cpp
)

# Make headers under the project's `src/` directory available to targets
target_include_directories(PulseSTL_Example PRIVATE ${PROJECT_SOURCE_DIR}/src)