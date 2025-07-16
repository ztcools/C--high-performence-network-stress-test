#include "../../include/core/Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace testpress
{

    void Logger::init()
    {
        // 初始化控制台彩色日志
        spdlog::set_default_logger(spdlog::stdout_color_mt("console"));
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
        spdlog::set_level(spdlog::level::info);
    }

} // namespace testpress