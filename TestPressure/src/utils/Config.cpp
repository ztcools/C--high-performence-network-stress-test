#include "../../include/utils/Config.h"
#include <iostream>

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
            app.exit(e);
            // 可以在这里添加自定义错误处理
            exit(1);
        }
        return config;
    }

} // namespace testpress