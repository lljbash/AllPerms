#include "all_perms_dict.h"
#include <algorithm>
#include <numeric>

using namespace all_perms;

void AllPermsDict::initialize(int n) {
    perms_.resize(n);
    std::iota(perms_.begin(), perms_.end(), 0);
}

void AllPermsDict::step() {
    //std::next_permutation(perms_.begin(), perms_.end());
    std::size_t perms_size = perms_.size();
    int end_ele1 = perms_[perms_size - 3];
    int end_ele2 = perms_[perms_size - 2];
    int end_ele3 = perms_[perms_size - 1];

    if (end_ele2 < end_ele3) {
        std::swap(perms_[perms_size - 1], perms_[perms_size - 2]);
    } 
    else {
        if (end_ele1 < end_ele2) {
            if (end_ele1 < end_ele3) {
                perms_[perms_size - 3] = end_ele3;
                perms_[perms_size - 2] = end_ele1;
                perms_[perms_size - 1] = end_ele2;
            }
            else {
                perms_[perms_size - 3] = end_ele2;
                perms_[perms_size - 2] = end_ele3;
                perms_[perms_size - 1] = end_ele1;
            }
        }
        else {
            int j = perms_size - 4;
            end_ele2 = end_ele1;
            end_ele1 = perms_[j];
            while (j > -1) {
                if (end_ele1 > end_ele2){
                    --j;
                    end_ele2 = end_ele1;
                    end_ele1 = perms_[j];
                }
                else {
                    break;
                }
            }
            if (j > -1) { 
                if (end_ele1 < end_ele3) {
                    perms_[j] = end_ele3;
                    perms_[j + 1] = end_ele1;
                    perms_[perms_size - 1] = end_ele2;
                    std::reverse(&perms_[j + 2], &perms_[perms_size - 1]);
                }
                else {
                    int l = perms_size - 2;
                    while (perms_[l] < end_ele1) {
                        --l;
                    }
                    perms_[j] = perms_[l];
                    perms_[l] = end_ele1;
                    std::reverse(&perms_[j + 1], &perms_[perms_size]);
                }   
            }
        }
    }
}

