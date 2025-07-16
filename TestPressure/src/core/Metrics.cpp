#include "../../include/core/Metrics.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

namespace testpress
{

    void Metrics::record(const RequestResult &result)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        results_.push_back(result);
    }

    void Metrics::report() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        size_t total = results_.size();
        size_t success = 0;
        double total_latency = 0;
        for (const auto &r : results_)
        {
            if (r.success)
                ++success;
            total_latency += r.latency_ms;
        }
        std::cout << "总请求数: " << total << std::endl;
        std::cout << "成功数: " << success << std::endl;
        std::cout << "成功率: " << (total ? (success * 100.0 / total) : 0) << "%" << std::endl;
        std::cout << "平均延迟: " << (total ? (total_latency / total) : 0) << " ms" << std::endl;
    }

    void Metrics::exportJson(const std::string &filename) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        nlohmann::json j;
        for (const auto &r : results_)
        {
            j.push_back({{"status_code", r.status_code}, {"latency_ms", r.latency_ms}, {"success", r.success}, {"error_msg", r.error_msg}});
        }
        std::ofstream ofs(filename);
        ofs << j.dump(2);
    }

    void Metrics::exportCsv(const std::string &filename) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::ofstream ofs(filename);
        ofs << "status_code,latency_ms,success,error_msg\n";
        for (const auto &r : results_)
        {
            ofs << r.status_code << "," << r.latency_ms << "," << r.success << "," << r.error_msg << "\n";
        }
    }

} // namespace testpress