cmake_minimum_required(VERSION 3.10)

# Project Name
project(MSH_Security_System)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where to find your Header (.h) files
include_directories(include)

# Collect all Source (.cpp) files
file(GLOB SOURCES "src/*.cpp")

# Create the Executable
add_executable(SecuritySystem ${SOURCES})

# Professional message for the console
message(STATUS "Security System Module configured successfully.")
