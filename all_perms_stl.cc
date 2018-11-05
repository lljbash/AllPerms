#include "all_perms_stl.h"
#include <algorithm>
#include <numeric>

using namespace all_perms;

void AllPermsSTL::initialize(int n) {
    perms_.resize(n);
    std::iota(perms_.begin(), perms_.end(), 0);
}

void AllPermsSTL::step() {
    std::next_permutation(perms_.begin(), perms_.end());
}

