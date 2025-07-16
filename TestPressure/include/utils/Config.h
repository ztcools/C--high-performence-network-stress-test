#pragma once
#include <string>
#include <CLI/CLI.hpp>

namespace testpress
{

    // 配置结构体
    struct Config
    {
        std::string url;            // 目标URL
        int threads = 4;            // 并发线程数
        int requests = 1000;        // 总请求数
        int qps = 0;                // 限流QPS，0为不限
        std::string method = "GET"; // 请求方法
        std::string body;           // POST请求体
        std::string output_file;    // 输出文件
    };

    // 解析命令行参数
    Config parseArgs(int argc, char **argv);

} // namespace testpress