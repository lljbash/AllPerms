#include "all_perms_agency_4.h"
#include <algorithm>

using namespace all_perms;

void AllPermsAgency4::initialize(int n) {
    AllPerms::initialize(n);
    agency_ = std::vector<int>(n+1);
    position_ = perms();
}

void AllPermsAgency4::step() {
    int n = perms().size();
    ++agency_.back();
    int i = n;
    for (; i > 1 && agency_[i] >= i; --i) {
        agency_[i] = 0;
        ++agency_[i-1];
    }
    if (i == 1) {
        initialize(n);
    }
    else {
        int d = (agency_[i-1] + ((i-1)&1) * agency_[i-2]) & 1;
        int j = position_[i-1];
        int k = j + (d * 2 - 1);
        std::swap(position_[perms()[j]], position_[perms()[k]]);
        std::swap(perms()[j], perms()[k]);
    }
}

