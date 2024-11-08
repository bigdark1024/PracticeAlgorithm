#include <iostream>
#include <queue>

using namespace std;

struct obj {
    int val;
    obj();
    obj(int x): val(x) {

    }
};

int main(int argc, char **argv) {
    queue<obj> q; // 创建一个队列q, 数据类型为obj
    if (q.empty()) {
        cout << "current queue is empty, and size : " << q.size() << endl;
    }
    q.push(obj(1));
    cout << "front1 : " << q.front().val << endl;
    q.push(obj(2));
    cout << "front2 : " << q.front().val << endl;
    q.push(obj(3));
    cout << "front3 : " << q.front().val << endl;
    q.pop();
    cout << "front4 : " << q.front().val << endl;
    q.push(obj(4));
    cout << "front5 : " << q.front().val << endl;
    if (!q.empty()) {
        cout << "current queue not empty, and size : " << q.size() << endl;
    }
    while (q.size() > 0) {
        obj front = q.front();
        cout << "pop value : " << front.val << endl;
        q.pop();
    }
    return 0;
}
