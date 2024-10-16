cmake_minimum_required(VERSION 3.14)
project(cub3D)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -fsanitize=address")

add_custom_target(build_libft
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
file(GLOB SOURCES "cmd/cub3D/**/*.c" "cmd/cub3D/*.c")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/cmd/cub3D/main.c")

message(STATUS "VariableName: ${SOURCES}")
add_library(testcub3D ${SOURCES})

set(LIBFT_PATH
"${CMAKE_SOURCE_DIR}/lib/libft.a"
"${CMAKE_SOURCE_DIR}/lib/libmlx_Linux.a"
)
target_link_libraries(testcub3D
${LIBFT_PATH} pthread Xext X11 m
)
target_include_directories(testcub3D
  PUBLIC ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)

enable_testing()
add_subdirectory(tests)
