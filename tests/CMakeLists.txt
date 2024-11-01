include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include(GoogleTest)

# Add test executables
## validation_test
add_executable(validation_test
validation/test_main.cpp
validation/test_map_validation.cpp
)
target_link_libraries(validation_test testcub3D gtest gtest_main)
gtest_add_tests(TARGET validation_test)

## map_utils_test
add_executable(map_utils_test test_map_utils.cpp)
target_link_libraries(map_utils_test testcub3D gtest gtest_main)
gtest_add_tests(TARGET map_utils_test)

## parse_cub/get_map_test
add_executable(parse_cub_test
parse_cub/test_get_map.cpp
parse_cub/test_get_conf.cpp
parse_cub/test_main.cpp
parse_cub/test_parse_cub.cpp
)
target_link_libraries(parse_cub_test testcub3D gtest gtest_main)
set(TEST_MAP_DIR "${CMAKE_SOURCE_DIR}/examples")
set(TEST_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
add_custom_command(
    TARGET parse_cub_test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${TEST_MAP_DIR}" "${CMAKE_BINARY_DIR}/tests/examples"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${TEST_ASSETS_DIR}" "${CMAKE_BINARY_DIR}/tests/examples"
)

gtest_add_tests(TARGET parse_cub_test)
