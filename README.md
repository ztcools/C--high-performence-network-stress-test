# TestPressure

C++ high-performance HTTP load testing tool — multi-threaded concurrent requests, real-time latency statistics, JSON/CSV result export.

## What it solves

Quickly evaluate an HTTP API's throughput and latency distribution. No heavyweight tools like wrk/JMeter required — one binary, ready to run, with programmatically exportable results.

## Tech stack

C++17 · CMake + FetchContent · cpr · spdlog · CLI11 · nlohmann/json · GoogleTest

## Features

- Multi-threaded concurrent HTTP GET/POST load testing
- QPS rate limiting (token bucket)
- Real-time stats: success rate, average/min/max latency
- JSON / CSV result export (special characters properly escaped in CSV)
- One-command Docker build & run
- Gitee CI automated build & test

## Usage

```bash
cd TestPressure && mkdir build && cd build
cmake .. && make -j$(nproc)

./TestPressure -u https://example.com/api -t 8 -n 1000
./TestPressure -u https://example.com/api -t 4 -n 500 -o result.csv
```
