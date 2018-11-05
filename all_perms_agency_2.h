#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsAgency2 : public AllPerms {
public:
    AllPermsAgency2() = default;
    virtual ~AllPermsAgency2() = default;
    AllPermsAgency2(const AllPermsAgency2 &) = delete;
    AllPerms & operator=(const AllPermsAgency2 &) = delete;

    virtual const std::vector<int> & perms() const override {
        return perms_;
    }

    virtual void initialize(int n) override;
    virtual void step() override;

private:
    std::vector<int> perms_;
    std::vector<int> agency_;
    std::vector<int> position_;
};

} // namespace all_perms

