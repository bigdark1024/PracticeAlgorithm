#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

void print_vector(std::vector<int>& vec)
{
//    for (int i = 0; i < vec.size(); ++i) {
//        std::cout << vec[i] << " ";
//    }
//    std::cout << std::endl;

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool comp(int x, int y)
{
    return (x < y);
}

struct obj_class {
    bool operator() (int x, int y) {
        return x < y;
    }
} my_object;

/* sort */
TEST(jiqiao_vector, t1)
{
    int datas[] = {36, 71, 12, 46, 35, 45, 18, 20, 5};
    std::vector<int> vec1(datas, datas + 9); // 36, 71, 12, 45, 35, 45, 18, 20, 5
    print_vector(vec1);

    // 使用默认比较 （operator <)
    std::sort(vec1.begin(), vec1.begin() + 3); // (12 36 71) 45, 35, 45, 18, 20, 5
    print_vector(vec1);

    // comp 函数
    std::sort(vec1.begin() + 3, vec1.end(), comp); // 36, 71, 12, (5 18 20 35 45 46)
    print_vector(vec1);

    // 仿函数
    std::sort(vec1.begin(), vec1.end(), [](int x, int y) ->bool {   // 71 46 45 36 35 20 18 12 5
        return x > y;
    });
    print_vector(vec1);

    // using object  as comp
    std::sort(vec1.begin(), vec1.end(), my_object); // 5 12 18 20 35 36 45 46 71
    print_vector(vec1);
}

/* 创建 */
TEST(jiqiao_vector, t2)
{
    vector<int> a;          // 创建一个空的vector, 数据类型int, 数组名 a
    vector<int> a1(100); // 创建一个vector, 数据类型int, 数组名a1, 元素个数100， 初值为0
    vector<int> a2(10, 666); // 创建一个vector, 数据类型Int，数组名a2, 元素个数10， 所有数初值为666
    vector<int>b(a2); // b 是 a2的副本
    vector<int>b1(a2.begin() + 3, a2.end() - 3); // 复制 [a2.begin(), a2.end() - 3)区间的元素到vector b1中
    print_vector(b1);
}

/* 增加 */
TEST(jiqiao_vector, t3)
{
    vector<int> a;          // 创建一个空的vector, 数据类型int, 数组名 a
    a.push_back(5); // 尾部增加一个元素
    print_vector(a);
    a.insert(a.begin() + 1, 10); // 在a.begin() + 1 指向元素前插入一个10
    print_vector(a);
//    a.insert(a.end(), 10); // 本例中a中只有一个元素，所以 a.begin() + 1 就是a.end()
    a.insert(a.begin() + 1, 5, 9); // 在 a.begin() + 1 指向元素前插入5个9
    print_vector(a);

    vector<int> b(a.begin(), a.begin() + 1); // 5
    b.push_back(-1);  // 5 1
    print_vector(b);

    a.insert(a.begin() + 1, b.begin(), b.end());
    print_vector(a);
}

/* 删除 */
TEST(jiqiao_vector, t4)
{
    vector<int> a;          // 创建一个空的vector, 数据类型int, 数组名 a
    a.push_back(5); // 尾部增加一个元素
    print_vector(a);
    a.insert(a.begin() + 1, 7, 9); // 在a.begin() + 1 指向元素前插入一个10
    print_vector(a);

    a.pop_back(); // 删除尾部最后一个元素
    print_vector(a);

    a.erase(a.begin() + 1); // 删除指定位置元素
    print_vector(a);

    a.erase(a.begin() + 3, a.end()); // 删除区间 [a.begin() + 3, a.end() -3)元素
    print_vector(a);

    a.clear(); // 清空所有元素
}

/* 二维 */
TEST(jiqiao_vector, t5)
{
    vector<vector<int>> a;
    a.push_back(vector<int> (5,0));
    a.push_back(vector<int> (5, -1));
    a.push_back(vector<int> (5, 1));

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (vector<vector<int>>::iterator it = a.begin(); it < a.end(); it++) {
        for (auto val : *it) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
