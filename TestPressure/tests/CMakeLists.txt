# tests/CMakeLists.txt

file(GLOB TEST_SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(TestPressTest ${TEST_SRC_FILES})

target_link_libraries(TestPressTest
    PRIVATE
        TestPressCore  # 链接核心库（关键修改）
        GTest::gtest_main
        cpr::cpr
        nlohmann_json::nlohmann_json
        spdlog::spdlog
        fmt::fmt
        CLI11::CLI11
        Threads::Threads
)

# 设置头文件搜索路径（如果需要）
target_include_directories(TestPressTest
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

enable_testing()
add_test(NAME TestPressTest COMMAND TestPressTest)