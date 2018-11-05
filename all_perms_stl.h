#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsSTL : public AllPerms {
public:
    AllPermsSTL() = default;
    virtual ~AllPermsSTL() = default;
    AllPermsSTL(const AllPermsSTL &) = delete;
    AllPerms & operator=(const AllPermsSTL &) = delete;

    virtual const std::vector<int> & perms() const override {
        return perms_;
    }

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> perms_;
};

} // namespace all_perms

