#include <gtest/gtest.h>
#include "../include/core/Metrics.h"
#include "../include/client/HttpClient.h"

using namespace testpress;

// 测试性能统计模块
TEST(MetricsTest, RecordAndReport)
{
    Metrics metrics;
    metrics.record({200, 10.5, true, ""});
    metrics.record({500, 20.0, false, "error"});
    testing::internal::CaptureStdout();
    metrics.report();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("总请求数"), std::string::npos);
}

// 测试HTTP客户端（仅接口，不实际请求）
TEST(HttpClientTest, Construct)
{
    HttpClient client("https://www.baidu.com");
    client.setTimeout(1000);
    // 这里只测试构造和设置超时
    SUCCEED();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}