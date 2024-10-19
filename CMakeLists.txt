cmake_minimum_required(VERSION 3.10)
project(QuantumPortfolioOptimizer)

set(CMAKE_CXX_STANDARD 17)

# Add directories for source and include files
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(QuantumPortfolioOptimizer ${SOURCES})
