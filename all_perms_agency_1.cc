#include "all_perms_agency_1.h"
#include <algorithm>

using namespace all_perms;

void AllPermsAgency1::initialize(int n) {
    AllPerms::initialize(n);
    agency_ = std::vector<int>(n - 1);
}

void AllPermsAgency1::step() {
    int n = perms().size();
    ++agency_.back();
    int i = n - 2;
    for (; i > 0 && agency_[i] > n-i-1; --i) {
        agency_[i] = 0;
        if (i > 0) {
            ++agency_[i-1];
        }
    }
    if (i < 0) {
        initialize(n);
    }
    else {
        int j = n - agency_[i];
        std::swap(perms()[i], perms()[j]);
        if (i + 1 < n - 1) {
            std::reverse(perms().begin()+(i+1), perms().end());
        }
    }
}

