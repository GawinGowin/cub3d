# tests/CMakeLists.txt

# GoogleTestのインクルードディレクトリを追加
include_directories(${CMAKE_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# テスト用の実行ファイルを追加
add_executable(test_valid_argument test_valid_argument.cpp)

# テスト実行ファイルにgtestライブラリをリンク
target_link_libraries(test_valid_argument gtest gtest_main)

# テストをCTESTに追加
add_test(NAME test_valid_argument COMMAND test_valid_argument)
