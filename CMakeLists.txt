cmake_minimum_required(VERSION 3.14)
project(cub3D)

# cmake_policy(SET CMP0135 NEW)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -fsanitize=address")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -fsanitize=address")

add_custom_target(init
    COMMAND ./install_minilibx.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating libmlx_Linux.a by running install_minilibx.sh"
)

# The cube3D sources
file(GLOB SOURCES "cmd/cub3D/**/*.c" "cmd/cub3D/*.c")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/cmd/cub3D/main.c")

# The libft sources
file(GLOB LIBFT_SOURCES "${CMAKE_SOURCE_DIR}/pkg/libft/*.c")

# Create the library
add_library(testcub3D ${SOURCES} ${LIBFT_SOURCES})
add_dependencies(testcub3D init)

# Link with necessary libraries
set(LIBRARIES
  ${CMAKE_SOURCE_DIR}/lib/libmlx_Linux.a
  pthread Xext X11 m
)
target_link_libraries(testcub3D ${LIBRARIES})

target_include_directories(testcub3D
  PUBLIC ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#   DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)

enable_testing()
add_subdirectory(tests)