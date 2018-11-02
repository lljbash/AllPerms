#include <string>
#include <memory>
#include <iostream>
#include "all_perms_stl.h"
#include "all_perms_agency_1.h"
#include "all_perms_agency_2.h"
#include "all_perms_agency_3.h"
#include "all_perms_dict.h"

using namespace all_perms;
using namespace std;

void test(const string &title, shared_ptr<AllPerms> p) {
    const int kNValidate = 9;
    const int kNSpeedTest1 = 12;
    const int kNSpeedTest2 = 32;
    const int64_t kMaxIterSpeedTest2 = 1000000000;

    cout << "*** " << title << " ***" << endl;
    p->validate(kNValidate);
    cout << "N = " << kNSpeedTest1 << ":\n  ";
    p->speed_test(kNSpeedTest1);
    cout << "N = " << kNSpeedTest2 << ", MaxIter = " << kMaxIterSpeedTest2 << ":\n  ";
    p->speed_test(kNSpeedTest2, kMaxIterSpeedTest2);
}

int main() {
    test("STL", make_shared<AllPermsSTL>());
    test("Agency1", make_shared<AllPermsAgency1>());
    test("Agency2", make_shared<AllPermsAgency2>());
    test("Agency3", make_shared<AllPermsAgency3>());
    test("Dict", make_shared<AllPermsDict>());
    return 0;
}

