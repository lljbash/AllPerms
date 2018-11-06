#pragma once

#include <deque>
#include <algorithm>
#include <cstdio>
#include "all_perms.h"

namespace all_perms {

class AllPermsQueue : public AllPerms {
public:
    AllPermsQueue() = default;
    virtual ~AllPermsQueue() = default;
    AllPermsQueue(const AllPermsQueue &) = delete;
    AllPerms & operator=(const AllPermsQueue &) = delete;

    virtual std::vector<int> perms() const override {
        auto perms = std::vector<int>({cir_perms_.begin(), cir_perms_.end()});
        std::rotate(perms.begin(), perms.begin() + cnt_, perms.end());
        return perms;
    }

    
    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::deque<int> cir_perms_;
    int cnt_;
};

} // namespace all_perms

