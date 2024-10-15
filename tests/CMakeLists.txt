include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include(GoogleTest)

add_executable(example_test test_example.cpp)
target_link_libraries(example_test testcub3D gtest gtest_main)

add_test(NAME test_example COMMAND example_test)
