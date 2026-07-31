#include "../../include/utils/Config.h"
#include <iostream>
#include <stdexcept>

namespace testpress
{

    Config parseArgs(int argc, char **argv)
    {
        Config config;
        CLI::App app{"TestPress 服务器性能测试工具"};
        app.add_option("-u,--url", config.url, "目标URL")->required();
        app.add_option("-t,--threads", config.threads, "并发线程数");
        app.add_option("-n,--requests", config.requests, "总请求数");
        app.add_option("--qps", config.qps, "限流QPS，0为不限");
        app.add_option("-X,--method", config.method, "请求方法(GET/POST)");
        app.add_option("-d,--body", config.body, "POST请求体(JSON)");
        app.add_option("-o,--output", config.output_file, "结果输出文件");
        // CLI11_PARSE(app, argc, argv);
        try
        {
            app.parse(argc, argv);
        }
        catch (const CLI::ParseError &e)
        {
            std::cerr << "解析参数失败: " << e.what() << "\n使用 --help 查看帮助" << std::endl;
            throw std::runtime_error("命令行参数解析失败");
        }
        return config;
    }

} // namespace testpress