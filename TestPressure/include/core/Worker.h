#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

namespace testpress
{

    // 任务调度器，负责多线程/异步发起请求
    class Worker
    {
    public:
        using Task = std::function<void()>;

        // 构造函数，指定线程数
        explicit Worker(int thread_num);

        // 启动所有线程，执行任务
        void start(const Task &task, int total_tasks);

        // 等待所有线程结束
        void join();

        // 停止任务
        void stop();

    private:
        int thread_num_;
        std::vector<std::thread> threads_;
        std::atomic<bool> running_{true};
    };

} // namespace testpress