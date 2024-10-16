include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include(GoogleTest)

# Add test executables
## map_validation_test
add_executable(map_validation_test test_map_validation.cpp)
target_link_libraries(map_validation_test testcub3D gtest gtest_main)

# Add tests
gtest_add_tests(TARGET map_validation_test)