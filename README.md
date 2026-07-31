# TestPressure

C++ 高性能 HTTP 压测工具 — 多线程并发发包、实时延迟统计、JSON/CSV 结果导出。

## 解决什么

需要快速评估 HTTP API 的吞吐能力和延迟分布。不用装 wrk/JMeter 等复杂工具，一个二进制直接跑，结果可编程导出。

## 技术栈

C++17 · CMake + FetchContent · cpr · spdlog · CLI11 · nlohmann/json · GoogleTest

## 功能

- 多线程并发 HTTP GET/POST 压测
- QPS 限流（令牌桶）
- 实时统计成功率、平均/最小/最大延迟
- JSON / CSV 结果导出（CSV 正确转义特殊字符）
- Docker 一键构建运行
- Gitee CI 自动编译测试

## 运行

```bash
cd TestPressure && mkdir build && cd build
cmake .. && make -j$(nproc)

./TestPressure -u https://example.com/api -t 8 -n 1000
./TestPressure -u https://example.com/api -t 4 -n 500 -o result.csv
```
