#include "all_perms_queue.h"
#include <algorithm>
#include <numeric>
#include <stack>

using namespace all_perms;

void AllPermsQueue::initialize(int n) {
    cnt_ = 0;
    cir_perms_.resize(n);
    std::iota(cir_perms_.begin(), cir_perms_.end(), 0);
}

void AllPermsQueue::step() {
    ++cnt_;
    int size = cir_perms_.size();
    if (cnt_ == size) {
        cnt_ = 0;
        int k = size - 2;
        cir_perms_.pop_back();
        for (; k == cir_perms_.front(); --k) {
            cir_perms_.pop_front();
        }
        cir_perms_.push_back(cir_perms_.front());
        cir_perms_.pop_front();
        for (++k; k < size; ++k) {
            cir_perms_.push_back(k);
        }
    }
}

