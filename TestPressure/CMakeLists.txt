cmake_minimum_required(VERSION 3.15)
project(TestPress LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#[[
# 依赖包管理（使用FetchContent）
include(FetchContent)

# fmt
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://kkgithub.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

# spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://kkgithub.com/gabime/spdlog.git
  GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(spdlog)

# cpr
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://kkgithub.com/libcpr/cpr.git
  GIT_TAG 1.10.5
)
set(CPR_BUILD_TESTS OFF)
set(CPR_FORCE_USE_SYSTEM_CURL OFF)
FetchContent_MakeAvailable(cpr)

# nlohmann_json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://kkgithub.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

# CLI11
FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://kkgithub.com/CLIUtils/CLI11.git
  GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(CLI11)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://kkgithub.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
]]
# 不使用 find_package，直接配置 Google Test
add_library(GTest::GTest UNKNOWN IMPORTED)
add_library(GTest::Main UNKNOWN IMPORTED)

# 设置库文件路径（根据你的系统调整）
set_target_properties(GTest::GTest PROPERTIES
    IMPORTED_LOCATION "/usr/lib64/libgtest.so"  # Fedora x86_64 路径
    INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
)

set_target_properties(GTest::Main PROPERTIES
    IMPORTED_LOCATION "/usr/lib64/libgtest_main.so"  # Fedora x86_64 路径
    INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
)
# 添加对nlohmann_json的查找
find_package(nlohmann_json REQUIRED)
# 其他find_package调用
find_package(Threads REQUIRED)
find_package(cpr REQUIRED)
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(CLI11 REQUIRED)
find_package(GTest REQUIRED)
# 源码
add_subdirectory(src)
add_subdirectory(tests) 