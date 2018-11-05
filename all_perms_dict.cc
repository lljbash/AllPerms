#include "all_perms_dict.h"
#include <algorithm>

using namespace all_perms;

void AllPermsDict::step() {
    //std::next_permutation(perms().begin(), perms().end());
    std::size_t perms_size = perms().size();
    int end_ele1 = perms()[perms_size - 3];
    int end_ele2 = perms()[perms_size - 2];
    int end_ele3 = perms()[perms_size - 1];

    if (end_ele2 < end_ele3) {
        std::swap(perms()[perms_size - 1], perms()[perms_size - 2]);
    } 
    else {
        if (end_ele1 < end_ele2) {
            if (end_ele1 < end_ele3) {
                perms()[perms_size - 3] = end_ele3;
                perms()[perms_size - 2] = end_ele1;
                perms()[perms_size - 1] = end_ele2;
            }
            else {
                perms()[perms_size - 3] = end_ele2;
                perms()[perms_size - 2] = end_ele3;
                perms()[perms_size - 1] = end_ele1;
            }
        }
        else {
            int j = perms_size - 4;
            end_ele2 = end_ele1;
            end_ele1 = perms()[j];
            while (j > -1) {
                if (end_ele1 > end_ele2){
                    --j;
                    end_ele2 = end_ele1;
                    end_ele1 = perms()[j];
                }
                else {
                    break;
                }
            }
            if (j > -1) { 
                if (end_ele1 < end_ele3) {
                    perms()[j] = end_ele3;
                    perms()[j + 1] = end_ele1;
                    perms()[perms_size - 1] = end_ele2;
                    std::reverse(&perms()[j + 2], &perms()[perms_size - 1]);
                }
                else {
                    int l = perms_size - 2;
                    while (perms()[l] < end_ele1) {
                        --l;
                    }
                    perms()[j] = perms()[l];
                    perms()[l] = end_ele1;
                    std::reverse(&perms()[j + 1], &perms()[perms_size]);
                }   
            }
        }
    }
}

