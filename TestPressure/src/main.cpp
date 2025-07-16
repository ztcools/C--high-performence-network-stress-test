#include "utils/Config.h"
#include "core/Logger.h"
#include "../include/core/Metrics.h"
#include "../include/core/Worker.h"
#include "../include/client/HttpClient.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <chrono>

using namespace testpress;

int main(int argc, char **argv)
{
    // 初始化日志
    Logger::init();

    // 解析命令行参数
    Config config;
    try
    {
        config = parseArgs(argc, argv);
    }
    catch (const std::exception &e)
    {
        spdlog::error("命令行参数错误: {}", e.what());
        return 1;
    }

    spdlog::info("目标URL: {}", config.url);
    spdlog::info("线程数: {}", config.threads);
    spdlog::info("总请求数: {}", config.requests);
    spdlog::info("请求方法: {}", config.method);

    // 初始化HTTP客户端
    HttpClient client(config.url);

    // 性能统计
    Metrics metrics;

    // 定义单次请求任务
    auto task = [&]()
    {
        auto start = std::chrono::steady_clock::now();
        bool success = false;
        long status = 0;
        std::string err;
        try
        {
            cpr::Response resp;
            if (config.method == "POST")
            {
                resp = client.post(nlohmann::json::parse(config.body.empty() ? "{}" : config.body));
            }
            else
            {
                resp = client.get();
            }
            status = resp.status_code;
            success = (resp.error.code == cpr::ErrorCode::OK && status >= 200 && status < 400);
            if (!success)
                err = resp.error.message;
        }
        catch (const std::exception &e)
        {
            err = e.what();
        }
        auto end = std::chrono::steady_clock::now();
        double latency = std::chrono::duration<double, std::milli>(end - start).count();
        metrics.record({status, latency, success, err});
    };

    // 启动多线程压力测试
    Worker worker(config.threads);
    worker.start(task, config.requests);
    worker.join();

    // 输出统计结果
    metrics.report();
    if (!config.output_file.empty())
    {
        if (config.output_file.find(".json") != std::string::npos)
        {
            metrics.exportJson(config.output_file);
        }
        else
        {
            metrics.exportCsv(config.output_file);
        }
        spdlog::info("结果已导出到 {}", config.output_file);
    }

    return 0;
}