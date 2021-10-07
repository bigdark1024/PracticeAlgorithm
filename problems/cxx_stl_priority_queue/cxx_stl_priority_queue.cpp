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
}

struct node {
  int x, y;
  bool operator<(const node &n) const {
    return this->x < n.x; // order by x in decending order
  }
};

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
