#include "all_perms_agency_4.h"
#include <algorithm>

using namespace all_perms;

void AllPermsAgency4::initialize(int n) {
    AllPerms::initialize(n);
    agency_ = std::vector<int>(n+1);
    direction_ = std::vector<int>(n+1);
}

void AllPermsAgency4::step() {
    int n = perms().size();
    ++agency_.back();
    int i = n;
    int l = -1;
    int r = n;
    for (; i > 1 && agency_[i] >= i; --i) {
        agency_[i] = 0;
        direction_[i] ^= 1;
        l += direction_[i];
        r -= direction_[i] ^ 1;
        ++agency_[i-1];
    }
    if (i == 1) {
        initialize(n);
    }
    else {
        int d = direction_[i];
        int j = d == 0 ? r - agency_[i] : l + agency_[i];
        int k = d == 0 ? j - 1 : j + 1;
        std::swap(perms()[j], perms()[k]);
    }
}

