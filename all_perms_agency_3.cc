#include "all_perms_agency_3.h"
#include <algorithm>
#include <numeric>

using namespace all_perms;

void AllPermsAgency3::initialize(int n) {
    perms_.resize(n);
    std::iota(perms_.begin(), perms_.end(), 0);
    agency_ = std::vector<int>(n - 1);
}

void AllPermsAgency3::step() {
    int n = perms_.size();
    ++agency_.back();
    int i = n - 2;
    for (; i >= 0 && agency_[i] > i+1; --i) {
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
            auto tmp = perms_.begin() + (n - k - 1);
            std::rotate(tmp, tmp + 1, perms_.end());
        }
        int k = j - agency_[i] + 1;
        std::swap(perms_[k-1], perms_[k]);
    }
}

