#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsSTL : public AllPerms {
public:
    AllPermsSTL() = default;
    virtual ~AllPermsSTL() = default;
    AllPermsSTL(const AllPermsSTL &) = delete;
    AllPerms & operator=(const AllPermsSTL &) = delete;

    virtual void step() override;
};

} // namespace all_perms

