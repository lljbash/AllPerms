#pragma once

#include "all_perms.h"

namespace all_perms {

class AllPermsDict : public AllPerms {
public:
    AllPermsDict() = default;
    virtual ~AllPermsDict() = default;
    AllPermsDict(const AllPermsDict &) = delete;
    AllPerms & operator=(const AllPermsDict &) = delete;

    virtual void step() override;
};

} // namespace all_perms

