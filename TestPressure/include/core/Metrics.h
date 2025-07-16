#pragma once
#include <vector>
#include <mutex>
#include <chrono>
#include <string>

namespace testpress
{

    // 单次请求结果
    struct RequestResult
    {
        long status_code;      // HTTP状态码
        double latency_ms;     // 延迟（毫秒）
        bool success;          // 是否成功
        std::string error_msg; // 错误信息
    };

    // 性能统计器
    class Metrics
    {
    public:
        // 记录一次请求结果
        void record(const RequestResult &result);

        // 统计并输出整体性能指标
        void report() const;

        // 导出为JSON/CSV
        void exportJson(const std::string &filename) const;
        void exportCsv(const std::string &filename) const;

    private:
        std::vector<RequestResult> results_;
        mutable std::mutex mutex_;
    };

} // namespace testpress