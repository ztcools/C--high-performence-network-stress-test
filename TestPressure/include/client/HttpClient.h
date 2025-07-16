#pragma once
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

namespace testpress
{

    // HTTP客户端，支持GET/POST等请求
    class HttpClient
    {
    public:
        // 构造函数，初始化目标URL
        explicit HttpClient(const std::string &url);

        // 发送GET请求，返回响应内容
        cpr::Response get(const nlohmann::json &headers = {});

        // 发送POST请求，body为JSON
        cpr::Response post(const nlohmann::json &body, const nlohmann::json &headers = {});

        // 设置超时时间（毫秒）
        void setTimeout(int ms);

    private:
        std::string url_;
        int timeout_ms_ = 5000;
    };

} // namespace testpress