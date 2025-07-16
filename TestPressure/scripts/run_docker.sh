#!/bin/bash
# 用于一键构建并运行TestPress的Docker脚本
set -e
cd "$(dirname "$0")/.."
docker build -t testpress ./docker
# 运行容器，自动删除
exec docker run --rm testpress "$@" 