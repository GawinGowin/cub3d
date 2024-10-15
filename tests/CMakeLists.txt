include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include(GoogleTest)


# Add test executables
## map_validation_test
add_executable(map_validation_test test_map_validation.cpp)
target_link_libraries(map_validation_test testcub3D gtest gtest_main)


# Add tests
add_test(NAME test_map_validation COMMAND map_validation_test)
