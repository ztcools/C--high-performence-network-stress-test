# TestPress

C++17 高性能 HTTP 压测工具 — 多线程并发 + 实时延迟统计 + JSON/CSV 导出。

## 功能

- HTTP GET/POST 压测，支持 JSON body
- 可配置并发线程数、总请求数、QPS 限流
- 实时统计：成功率、平均延迟、最小/最大延迟
- 导出 JSON / CSV 格式结果（CSV 正确转义特殊字符）
- Docker 一键构建运行
- GoogleTest 单元测试

## 技术栈

C++17 · CMake + FetchContent · [cpr](https://github.com/libcpr/cpr) · [spdlog](https://github.com/gabime/spdlog) · [CLI11](https://github.com/CLIUtils/CLI11) · [nlohmann/json](https://github.com/nlohmann/json)

## 运行

```bash
cd TestPressure && mkdir build && cd build
cmake .. && make -j$(nproc)
./TestPressure --help

# 示例
./TestPressure -u https://example.com/api -t 8 -n 1000
./TestPressure -u https://example.com/api -t 4 -n 500 -o result.csv
```

## CLI 参数

| 选项 | 说明 | 默认值 |
|------|------|--------|
| `-u, --url` | 目标 URL（必填） | — |
| `-t, --threads` | 并发线程数 | 4 |
| `-n, --requests` | 总请求数 | 1000 |
| `--qps` | QPS 限流（0=不限） | 0 |
| `-X, --method` | GET / POST | GET |
| `-d, --body` | POST JSON 请求体 | — |
| `-o, --output` | 结果输出 (.json/.csv) | — |

## Docker

```bash
cd TestPressure/docker
docker build -t testpress .
docker run --rm testpress -u https://example.com -t 4 -n 100
```
