# src/CMakeLists.txt

# 1. 创建核心库（包含所有实现）
file(GLOB_RECURSE CORE_SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/client/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
)

add_library(TestPressCore STATIC ${CORE_SRC_FILES})

target_include_directories(TestPressCore
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include  # 导出头文件路径
)

target_link_libraries(TestPressCore
    PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
        spdlog::spdlog
        fmt::fmt
        CLI11::CLI11
        Threads::Threads
)

# 2. 创建主程序（仅包含 main.cpp）
file(GLOB MAIN_SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

add_executable(TestPress ${MAIN_SRC_FILES})

target_link_libraries(TestPress
    PRIVATE
        TestPressCore  # 链接核心库
)