#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsAgency4 : public AllPerms {
public:
    AllPermsAgency4() = default;
    virtual ~AllPermsAgency4() = default;
    AllPermsAgency4(const AllPermsAgency4 &) = delete;
    AllPerms & operator=(const AllPermsAgency4 &) = delete;

    virtual const std::vector<int> & perms() const override {
        return perms_;
    }

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> perms_;
    std::vector<int> agency_;
    std::vector<int> direction_;
};

} // namespace all_perms

