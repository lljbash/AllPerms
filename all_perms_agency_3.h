#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsAgency3 : public AllPerms {
public:
    AllPermsAgency3() = default;
    virtual ~AllPermsAgency3() = default;
    AllPermsAgency3(const AllPermsAgency3 &) = delete;
    AllPerms & operator=(const AllPermsAgency3 &) = delete;

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> agency_;
};

} // namespace all_perms

