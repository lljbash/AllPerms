#include "all_perms_stl.h"
#include <algorithm>

using namespace all_perms;

void AllPermsSTL::step() {
    std::next_permutation(perms().begin(), perms().end());
}

