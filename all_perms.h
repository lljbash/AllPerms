#pragma once

#include <vector>
#include <iostream>

namespace all_perms {

class AllPerms {
public:
    AllPerms() = default;
    virtual ~AllPerms() = default;
    AllPerms(const AllPerms &) = delete;
    AllPerms & operator=(const AllPerms &) = delete;

    static int64_t factorial(int64_t n) {
        return n < 3 ? n : n * factorial(n - 1);
    }

    bool validate(int n, bool logging = true, std::ostream &out = std::cout);
    int64_t speed_test(int n, int64_t max_iter = -1, bool logging = true, std::ostream &out = std::cout);

    virtual std::vector<int> perms() const = 0;

    virtual void initialize(int n) = 0;
    virtual void step() = 0;
};

} // namespace all_perms

