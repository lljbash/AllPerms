#include "all_perms_stl.h"
#include <algorithm>

using namespace all_perms;

void AllPermsSTL::initialize(int n) {
    perms().resize(n);
    for (int i = 0; i < n; ++i) {
        perms()[i] = i;
    }
}

void AllPermsSTL::step() {
    std::next_permutation(perms().begin(), perms().end());
}

