#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsDict : public AllPerms {
public:
    AllPermsDict() = default;
    virtual ~AllPermsDict() = default;
    AllPermsDict(const AllPermsDict &) = delete;
    AllPerms & operator=(const AllPermsDict &) = delete;

    virtual std::vector<int> perms() const override {
        return perms_;
    }

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> perms_;
};

} // namespace all_perms

