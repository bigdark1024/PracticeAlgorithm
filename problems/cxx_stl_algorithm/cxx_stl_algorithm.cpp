#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

TEST(cxx_stl_algorithm, case1) {
    vector<int> c = {0,1,2,3,4,5,6,7,8,9,1};
    cout << "size : " << c.size() << endl;

    remove(c.begin(), c.end(), 1);
    cout << "size : " << c.size() << endl;

    vector<int>::iterator newEnd(remove(c.begin(), c.end(), 1));

    vector<int>::iterator iter = c.begin();
    while(iter + 1 != newEnd) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
