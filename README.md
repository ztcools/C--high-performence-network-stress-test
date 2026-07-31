# TestPressure

A high-performance C++ network stress-testing tool built with **C++17**, using epoll-based event-driven architecture and multi-threaded concurrency for HTTP load testing.

## Features

- ✅ **Multi-threaded** — Configurable worker threads for concurrent request generation
- ✅ **HTTP GET/POST** — Supports JSON body POST requests
- ✅ **Real-time Metrics** — Records latency, success rate, and error messages per request
- ✅ **Export Results** — JSON and CSV output with proper CSV escaping
- ✅ **CLI-driven** — Full command-line argument parsing via CLI11
- ✅ **Structured Logging** — spdlog-based colored console output
- ✅ **Docker-ready** — Includes Dockerfile and CI pipeline (Gitee)

## Quick Start

```bash
# Build
cd TestPressure && mkdir build && cd build
cmake .. && make -j$(nproc)

# Run
./testpressure -u https://example.com/api -t 8 -n 1000

# Output CSV
./testpressure -u https://example.com/api -t 4 -n 500 -o results.csv
```

## CLI Options

| Flag | Description | Default |
|------|-------------|---------|
| `-u, --url` | Target URL (**required**) | — |
| `-t, --threads` | Concurrent threads | 4 |
| `-n, --requests` | Total request count | 1000 |
| `--qps` | Rate-limit QPS (0 = unlimited) | 0 |
| `-X, --method` | HTTP method (GET/POST) | GET |
| `-d, --body` | POST request body (JSON) | — |
| `-o, --output` | Output file (.json or .csv) | — |

## Dependencies

- [CPR](https://github.com/libcpr/cpr) — C++ HTTP client
- [nlohmann/json](https://github.com/nlohmann/json) — JSON parsing
- [CLI11](https://github.com/CLIUtils/CLI11) — CLI argument parsing
- [spdlog](https://github.com/gabime/spdlog) — Fast C++ logging

## Docker

```bash
bash scripts/run_docker.sh
```

## License

MIT
