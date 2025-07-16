#include "../../include/core/Worker.h"

namespace testpress
{

    Worker::Worker(int thread_num) : thread_num_(thread_num) {}

    void Worker::start(const Task &task, int total_tasks)
    {
        int tasks_per_thread = total_tasks / thread_num_;
        int remainder = total_tasks % thread_num_;
        for (int i = 0; i < thread_num_; ++i)
        {
            int count = tasks_per_thread + (i < remainder ? 1 : 0);
            threads_.emplace_back([this, task, count]()
                                  {
            for (int j = 0; j < count && running_; ++j) {
                task();
            } });
        }
    }

    void Worker::join()
    {
        for (auto &t : threads_)
        {
            if (t.joinable())
                t.join();
        }
        threads_.clear();
    }

    void Worker::stop()
    {
        running_ = false;
    }

} // namespace testpress