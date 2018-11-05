#include "all_perms.h"
#include <set>
#include <unordered_set>
#include <chrono>

using namespace all_perms;

bool AllPerms::validate(int n, bool logging, std::ostream &out) {
    initialize(n);
    int64_t max_iter = factorial(n);
    std::set<std::vector<int>> validate_set = {perms()};
    for (int64_t i = 1; i < max_iter; ++i) {
        step();
        auto res = validate_set.insert(perms());
        bool flag = res.second;
        if (flag) {
            std::unordered_set<int> rep_set;
            for (int p : perms()) {
                if (p < 0 || p >= n) {
                    flag = false;
                    break;
                }
                auto res = rep_set.insert(p);
                if (!res.second) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            if (logging) {
                out << "Validation error!" << std::endl;
            }
            return false;
        }
    }
    if (logging) {
        out << "Validated!" << std::endl;
    }
    return true;
}

int64_t AllPerms::speed_test(int n, int64_t max_iter, bool logging, std::ostream &out) {
    initialize(n);
    if (max_iter < 0) {
        max_iter = factorial(n);
    }
    auto start = std::chrono::steady_clock::now();
    for (int64_t i = 1; i < max_iter; ++i) {
        step();
    }
    auto end = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    if (logging) {
        out << "Elapsed time: " << t << "ms" << std::endl;
    }
    return t;
}

