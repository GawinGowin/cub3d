include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCES
  test_example.cpp
  # 他のテストファイルを追加する場合はここに記述する
)

add_executable(cube3d_unit_test ${TEST_SOURCES})

target_link_libraries(cube3d_unit_test testcub3D gtest gtest_main)

add_test(NAME cube3d_unit_test COMMAND cube3d_unit_test)