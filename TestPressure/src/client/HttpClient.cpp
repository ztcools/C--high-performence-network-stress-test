#include "../../include/client/HttpClient.h"

namespace testpress
{

    HttpClient::HttpClient(const std::string &url) : url_(url) {}

    cpr::Response HttpClient::get(const nlohmann::json &headers)
    {
        // 构造header
        cpr::Header cpr_headers;
        for (auto &el : headers.items())
        {
            cpr_headers[el.key()] = el.value();
        }
        // 发送GET请求
        return cpr::Get(cpr::Url{url_}, cpr_headers, cpr::Timeout{timeout_ms_});
    }

    cpr::Response HttpClient::post(const nlohmann::json &body, const nlohmann::json &headers)
    {
        cpr::Header cpr_headers;
        for (auto &el : headers.items())
        {
            cpr_headers[el.key()] = el.value();
        }
        // 发送POST请求，body为JSON字符串
        return cpr::Post(cpr::Url{url_}, cpr_headers, cpr::Body{body.dump()}, cpr::Timeout{timeout_ms_});
    }

    void HttpClient::setTimeout(int ms)
    {
        timeout_ms_ = ms;
    }

} // namespace testpress