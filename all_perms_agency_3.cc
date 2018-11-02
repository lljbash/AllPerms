#include "all_perms_agency_3.h"
#include <algorithm>

using namespace all_perms;

void AllPermsAgency3::initialize(int n) {
    AllPerms::initialize(n);
    agency_ = std::vector<int>(n - 1);
}

void AllPermsAgency3::step() {
    int n = perms().size();
    ++agency_.back();
    int i = n - 2;
    for (; i > 0 && agency_[i] > i+1; --i) {
        agency_[i] = 0;
        if (i > 0) {
            ++agency_[i-1];
        }
    }
    if (i < 0) {
        initialize(n);
    }
    else {
        int j = i + 1;
        for (int k = j + 1; k < n; ++k) {
            auto tmp = perms().begin() + (n - k - 1);
            std::rotate(tmp, tmp + 1, perms().end());
        }
        int k = j - agency_[i] + 1;
        std::swap(perms()[k-1], perms()[k]);
    }
}

