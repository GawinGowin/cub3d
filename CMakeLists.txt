cmake_minimum_required(VERSION 3.10)
project(cub3D)

set(CMAKE_C_STANDARD 11)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(include)

# link directories
link_directories(lib)

# Source files
file(GLOB SOURCES "cmd/cub3D/**.c")
add_executable(cub3D ${SOURCES})

target_link_libraries(cub3D pthread mlx_Linux Xext X11 m ft)

# テスト用の設定
# add_subdirectory(tests)