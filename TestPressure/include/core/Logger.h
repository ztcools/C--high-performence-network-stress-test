#pragma once
#include <spdlog/spdlog.h>

namespace testpress
{

    // 日志系统，封装spdlog
    class Logger
    {
    public:
        // 初始化日志（可指定日志级别、文件等）
        static void init();
    };

} // namespace testpress