# 基于 Fedora 的镜像
FROM fedora:41

# 安装依赖
RUN dnf install -y git cmake gcc-c++ make curl openssl-devel

# 拷贝项目文件
WORKDIR /app
COPY . /app

# 构建
RUN mkdir -p build && cd build \
    && cmake .. \
    && make -j

# 运行（默认显示帮助）
CMD ["/app/build/TestPress", "--help"] 