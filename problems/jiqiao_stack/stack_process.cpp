#include <iostream>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

struct obj {
    int val;
    obj();
    obj(int x): val(x) {

    }
};

/* 基础操作 */
TEST(jiqiao_stack, t1)
{
    stack<obj> s; // 创建一个空栈s, 数据类型为int
    if (s.empty()) {
        cout << "current stack is empty, and size : " << s.size() << endl;
    }
    s.push(obj(1));
    cout << "top1 : " << s.top().val << endl;
    s.push(obj(2));
    cout << "top2 : " << s.top().val << endl;
    s.push(obj(3));
    cout << "top3 : " << s.top().val << endl;
    s.pop();
    cout << "top4 : " << s.top().val << endl;
    s.push(obj(4));
    cout << "top5 : " << s.top().val << endl;
    if (!s.empty()) {
        cout << "current stack not empty, and size : " << s.size() << endl;
    }
    while (s.size() > 0) {
        obj top = s.top();
        cout << "pop value : " << top.val << endl;
        s.pop();
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
