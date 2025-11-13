cmake_minimum_required(VERSION 3.10)

project(GNL)

# Specify C standards
set(CMAKE_C_STANDARD 99)

# Add source files to the executable
add_executable(get_next_line.c get_next_line_utils.c main.c)
