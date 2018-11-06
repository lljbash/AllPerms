#include "all_perms_agency_2.h"
#include <algorithm>
#include <numeric>

using namespace all_perms;

void AllPermsAgency2::initialize(int n) {
    perms_.resize(n);
    std::iota(perms_.begin(), perms_.end(), 0);
    agency_ = std::vector<int>(n - 1);
    position_ = perms_;
}

void AllPermsAgency2::step() {
    int n = perms_.size();
    ++agency_.back();
    int i = n - 2;
    for (; i >= 0 && agency_[i] > n-i-1; --i) {
        agency_[i] = 0;
        if (i > 0) {
            ++agency_[i-1];
        }
    }
    if (i < 0) {
        initialize(n);
    }
    else {
        int k = n - i - 1;
        int j = k - agency_[i];
        for (int l = 0, r = k-1; l < r; ++l, --r) {
            std::swap(perms_[position_[l]], perms_[position_[r]]);
            std::swap(position_[l], position_[r]);
        }
        std::swap(perms_[position_[j]], perms_[position_[k]]);
        std::swap(position_[j], position_[k]);
    }
}

