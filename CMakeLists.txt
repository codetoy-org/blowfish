cmake_minimum_required(VERSION 3.22)	# CMake version check
project(blowfish)						# Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)				# Enable c++20 standard

# Add executable target
add_executable(blowfish)

# Add source directory
add_subdirectory(src)