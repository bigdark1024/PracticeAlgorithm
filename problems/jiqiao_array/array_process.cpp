#include <iostream>
#include <array>
using namespace std;

int main(int argc, char **argv) {
    // 声明一个大小为100个的int类型数组，初始值全0
    array<int, 100> a {};

    // 声明一个大小为100个的int类型数组，初始化部分值，其余全0
    array<int, 10> b {1, 2, 3};

    return 0;
}
