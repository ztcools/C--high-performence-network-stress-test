# TestPress 服务器性能测试工具

## 项目简介
TestPress 是一个高性能、跨平台的服务器性能测试工具，采用现代C++开发，支持多线程/异步、丰富的性能指标统计

## 主要功能
- 支持 HTTP/HTTPS 性能压测
- 支持多线程/异步请求
- 支持自定义并发数、QPS、请求体等
- 实时统计吞吐量、延迟、错误率等
- 支持命令行参数
- 日志系统
- 单元测试
- 结果输出为终端和 CSV/JSON 文件

## 技术栈
- C++17
- CMake
- Docker（基于 Fedora）
- spdlog、fmt、cpr、nlohmann/json、CLI11、GoogleTest
- Gitee Go 持续集成

## 目录结构
```text
TestPress/
├── CMakeLists.txt           # CMake主配置
├── docker/                  # Docker相关
│   └── Dockerfile
├── include/                 # 头文件
│   ├── client/              # HTTP客户端模块
│   ├── core/                # 性能统计/调度/日志
│   └── utils/               # 配置与工具
├── src/                     # 源文件
│   ├── client/
│   ├── core/
│   └── utils/
│   └── main.cpp             # 程序入口
├── tests/                   # 单元测试
├── third_party/             # 外部依赖
├── scripts/                 # 辅助脚本
├── .gitee/                  # Gitee Go CI配置
├── .gitignore
└── README.md
```

## 编译与运行
```bash
# 安装依赖（Fedora）
sudo dnf install -y git cmake gcc-c++ make curl openssl-devel

# 编译
mkdir -p build && cd build
cmake ..
make -j

# 运行
./TestPress --help
```

## Docker 构建与运行
```bash
cd docker
# 构建镜像
docker build -t testpress .
# 运行容器
docker run --rm testpress
```

## 持续集成（Gitee Go）
- 见 .gitee/ 目录下 ci.yml 配置，支持自动编译与单元测试。

## 联系方式
- 作者：zt
- 邮箱：3614644417@qq.com

---