#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void demo1(void)
{
    priority_queue<int> pq;

    string ss = typeid(pq).name();
    std::cout << typeid(decltype(pq)).name() << std::endl;


    vector<char> vc = { 'a','b','c','d','e' };
    priority_queue<char, deque<char>, greater<char>> pq2(vc.begin(), vc.end());	//现在是小堆
    cout << typeid(pq2).name() << endl;	//查看类型
    cout << "==========================" << endl;
    while (!pq2.empty()) {
        //将小堆中的堆顶元素，依次打印
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;
}

struct tmp1 { // 重载运算符 <
    int x;
    tmp1(int a) {
        x = a;
    }
    bool operator<(const tmp1& a) const {
        return x < a.x; // 大顶堆
    }
};

struct tmp2 { // 重写仿函数
    bool operator() (tmp1 a, tmp1 b) {
        return a.x < b.x; // 大顶堆
    }
};

int main(int argc, char **argv) {
    demo1();

    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);

    priority_queue<tmp1> pd;
    pd.push(b);
    pd.push(c);
    pd.push(a);

    while (!pd.empty()) {
        std::cout << pd.top().x << std::endl;
        pd.pop();
    }

    priority_queue<tmp1, vector<tmp1>, tmp2> pd_sort;
    pd_sort.push(b);
    pd_sort.push(c);
    pd_sort.push(a);
    while (!pd_sort.empty()) {
        std::cout << pd_sort.top().x << std::endl;
        pd_sort.pop();
    }
    return 0;
}
