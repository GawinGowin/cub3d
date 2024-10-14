cmake_minimum_required(VERSION 3.14)
project(cub3D)

set(CMAKE_C_STANDARD 17)

add_custom_target(build_libft
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
file(GLOB SOURCES "cmd/cub3D/**/*.c" "cmd/cub3D/*.c")
add_executable(cub3D ${SOURCES})

set(LIBFT_PATH
"${CMAKE_SOURCE_DIR}/lib/libft.a"
"${CMAKE_SOURCE_DIR}/lib/libmlx_Linux.a"
)
target_link_libraries(cub3D
${LIBFT_PATH} pthread Xext X11 m
)
target_include_directories(cub3D
  PUBLIC ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests)
enable_testing()