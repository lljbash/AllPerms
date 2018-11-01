#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsAgency1 : public AllPerms {
public:
    AllPermsAgency1() = default;
    virtual ~AllPermsAgency1() = default;
    AllPermsAgency1(const AllPermsAgency1 &) = delete;
    AllPerms & operator=(const AllPermsAgency1 &) = delete;

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> agency_;
};

} // namespace all_perms

