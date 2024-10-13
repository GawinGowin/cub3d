cmake_minimum_required(VERSION 3.10)
project(cub3D_tests)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

# link directories
link_directories(../lib)

# Source files
file(GLOB TEST_SOURCES "src/**.cpp")
add_executable(cub3D_tests ${TEST_SOURCES})

# Link libraries
target_link_libraries(cub3D_tests pthread mlx_Linux Xext X11 m ft)
