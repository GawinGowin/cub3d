include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include(GoogleTest)


# Add test executables
## example_test
add_executable(example_test test_example.cpp)
target_link_libraries(example_test testcub3D gtest gtest_main)

## map_validation_test
add_executable(map_validation_test test_map_validation.cpp)
target_link_libraries(map_validation_test testcub3D gtest gtest_main)


# Add tests
add_test(NAME test_example COMMAND example_test)
add_test(NAME test_map_validation COMMAND map_validation_test)
