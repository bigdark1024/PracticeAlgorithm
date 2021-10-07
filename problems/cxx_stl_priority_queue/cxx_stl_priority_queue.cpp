#include "headers.h"

TEST(cxx_stl_priority_queue, cxx_stl_priority_queue) {
    priority_queue<int> que;
    que.push(7);
    que.push(5);
    que.push(-2);
    que.push(1);
    que.push(6);

    cout << que.size() << endl;
    while(!que.empty()) {
        cout << que.top() << " ";
        que.pop();
    }

    cout << endl;
    return 0;
} 

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
