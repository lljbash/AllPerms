#include "all_perms_agency_1.h"
#include <algorithm>
#include <numeric>

using namespace all_perms;

void AllPermsAgency1::initialize(int n) {
    perms_.resize(n);
    std::iota(perms_.begin(), perms_.end(), 0);
    agency_ = std::vector<int>(n - 1);
}

void AllPermsAgency1::step() {
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
        int j = n - agency_[i];
        std::swap(perms_[i], perms_[j]);
        if (i + 1 < n - 1) {
            std::reverse(perms_.begin()+(i+1), perms_.end());
        }
    }
}

