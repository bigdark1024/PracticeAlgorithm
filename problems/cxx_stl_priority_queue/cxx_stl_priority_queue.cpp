#include "headers.h"

template<typename T>
void print_queue(T &q) {
  while (!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << '\n';
}

TEST(cxx_stl_priority_queue, testcase1) {
  priority_queue<int> que; // default greater priority queue
  que.push(7);
  que.push(5);
  que.push(-2);
  que.push(1);
    que.push(6);

    cout << que.size() << endl;
    print_queue(que);

    priority_queue<int, vector<int>, std::less<int>> que2;  // less<int> 大顶堆
    for (int n: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        que2.push(n);
    }
    print_queue(que2);

    priority_queue<int, vector<int>, std::greater<int>> que3; // greater<int> 小顶堆
    for (int n: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        que3.push(n);
    }
    print_queue(que3);
}

// 运算符重载<
struct node {
    int x, y;
    bool operator<(const node &n) const {
        return this->x < n.x; // order by x in decending order
    }
};

// 自定义类型做优先队列元素例子1
TEST(cxx_stl_priority_queue, testcase2) {
  priority_queue<node> que;
  que.push((node) {1, 5});
    que.push((node) {2, 3});
    que.push((node) {-5, 7});

    while (!que.empty()) {
        cout << que.top().x << " ";
        que.pop();
    }
    cout << endl;
}

struct tmp1 {
    int x;

    tmp1(int num) {
        this->x = num;
    }

    bool operator<(const tmp1 &num) const { // 两个const比较重要
        return this->x < num.x; // 大顶堆， 降序
    }
};

// 自定义类型做优先队列元素例子2
TEST(cxx_stl_priority_queue, testcase3) {
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(a);
    d.push(b);
    d.push(c);
    while (!d.empty()) {
        cout << d.top().x << endl;
        d.pop();
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
