#include <vector>
#include <algorithm> // sort, remove, unique
#include <string>
#include <sstream>  // stringstream
#include <cstdlib> // stoi, atoi

#include <gtest/gtest.h>

using namespace std;

TEST(cxx_stl_algorithm, case1_remove) {
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

/**
 *  string 大小写转换
 *  将序列开始地址beg到结束地址end大小写转换，把结果保存到起始地址为dest的序列中。
 *
 *  #include <cctype> // toupper / tolower
 *  #include <algorithm> // transform
 *
 *  transform(beg, end, dest, ::tolower)
 *  transform(beg, end, dest, ::toupper)
 */
TEST(cxx_stl_algorithm, case2) {
    // 小写转大写
    string s = "abcABCdef";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    // 大写转小写
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    char ch = 'A';
    // 单个字符
    ch = tolower(ch);
    std::cout << ch << std::endl;

    ch = 'b';
    ch = ::toupper(ch);
    std::cout << ch << std::endl;
}

/**
 * 判断字符是不是字母、数字、大小写
 * */
TEST(cxx_stl_algorithm, case3) {
    // isalpha()用来判断一个字符是否是字母，如果是字符则返回非零，否则返回零。
    std::cout << "==========isalpha========" << std::endl;
    std::cout << isalpha('a') << std::endl; // 非零
    std::cout << isalpha('A') << std::endl; // 非零
    std::cout << isalpha('-') << std::endl; // 零
    std::cout << isalpha('2') << std::endl; // 零
    // isalnum()用来判断一个字符是否位数字和字母，也就是说判断一个字符是否属于a~z||A~Z||0~9
    std::cout << "==========isalnum========" << std::endl;
    std::cout << isalnum('a') << std::endl; // 非零
    std::cout << isalnum('.') << std::endl; // 零
    std::cout << isalnum('2') << std::endl; // 零
    // islower()判断一个字符是否为小写字母，也就是是否属于 a~z。
    std::cout << "==========islower========" << std::endl;
    std::cout << islower('a') << std::endl; // 非零
    std::cout << islower('A') << std::endl; // 零
    std::cout << islower('2') << std::endl; // 零
    // isupper判断一个字符是否为大写字母
    std::cout << "==========isupper========" << std::endl;
    std::cout << isupper('a') << std::endl; // 零
    std::cout << isupper('2') << std::endl; // 零
    std::cout << isupper('A') << std::endl; // 非零

    // 以上均为宏定义，并非真实函数
}

/**
 * 字符串整形转换函数
 * */
TEST(cxx_stl_algorithm, case5) {
    string s = "10";
    // 字符串转整形
    // stoi(字符串， 起始位置， n进制)， 将n进制的字符串转换为十进制
    int a = stoi(s); // s -> a
    std::cout << "a = " << a << std::endl;

    // 会自动忽略小数点以后得部分以及字符、空格
    std::size_t pos {};
    a = stoi("   -15aa10", &pos); // a:15
    std::cout <<"a:" << a << "  pos: " << pos << '\n';

    // stringstream
    // #include <sstream> 可将致函数字的字符串转化为整型，也可将数字和小数点组成的字符串转化为浮点型
    // 即 string -> int, string -> double
    s = "123.4";
    double x;
    stringstream ss;
    ss << s;
    ss >> x;
    std::cout << "string->double = " << x << std::endl;

    // atoi(s)将字符串转化为整型，s为const char*类型
    // int atoi( const char* str );
    int res = atoi(s.c_str());
    std::cout << "string->int = " << res << std::endl;

    // 整型转字符串
    // 方法一：
    // stringstream: 可将整型、浮点型数字转化为字符串， 即int -> string, double -> string
    double x2 = 123.4;
    stringstream ss2;
    string s2;
    ss2 << x2;
    ss2 >> s2;
    std::cout << "string -> double = " << s2 << std::endl;

    // 方法二
    // to_string() 可将整型转化为字符串，不推荐将浮点型转化为字符串
    int strToInt = 12;
    string s3;
    s3 = to_string(strToInt);
    std::cout << "string -> int = " << s3 << std::endl;
}

static void PrintVec(std::vector<int> &vec) {
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * unique()去重
 * */
TEST(cxx_stl_algorithm, case6) {
    // 函数原型
    // template< class ForwardIt > ForwardIt unique( ForwardIt first, ForwardIt last );
    // unique(起始位置，末尾位置)
    std::vector<int> v {1, 2, 1, 1, 3, 3, 3, 4, 5, 4};

    // remove consecutive (adjacent) duplicates 删除连续（相邻）副本
    auto last = std::unique(v.begin(), v.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    // 返回元素下标 pos - vec.begin()
    PrintVec(v);

    // 排序后，再删除相邻副本
    // sort followed by unique, to remove all duplicates
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    PrintVec(v);
    last = std::unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    PrintVec(v);
}

/**
 *  二分查找
 * */
TEST(cxx_stl_algorithm, case7_lower_upper_bound) {
    // 必须有序才能用，所谓“有序”，并不是要求[First, last]区域内数据严格按照某个排序规则进行升序或降序排序，
    // 只要满足使element < val(或者comp(val, element)成立的元素都位于不成立元素的前面。
    // lower_bound(起始位置， 末尾位置， target): 查找第一个大于或等于target目标值的地址；如果区间内所有元素都小于target，返回last地址，且last地址是越界的。
    // upper_bound(起始位置， 末尾位置， target): 查找第一个大于target目标值的地址，如果target大于区间内所有元素，则返回last地址， 且last地址是越界的。
    // binary_search(起始位置， 末尾位置， target): 查找target是否存在于数组或者vector中，找到返回true, 否则返回false
    int a[] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 10};
    std::cout << std::lower_bound(a, a + 10, 0) - a << std::endl;
    std::cout << std::lower_bound(std::begin(a), std::end(a), 1) - a << std::endl;
    std::cout << std::lower_bound(std::begin(a), std::end(a), 3) - a << std::endl;
    std::cout << std::lower_bound(std::begin(a), std::end(a), 4) - a << std::endl;
    std::cout << std::lower_bound(std::begin(a), std::end(a), 5) - a << std::endl;

    std::cout << std::upper_bound(std::begin(a), std::end(a), 0) - a << std::endl;
    std::cout << std::upper_bound(std::begin(a), std::end(a), 1) - a << std::endl;
    std::cout << std::upper_bound(std::begin(a), std::end(a), 3) - a << std::endl;
    std::cout << std::upper_bound(std::begin(a), std::end(a), 4) - a << std::endl;
    std::cout << std::upper_bound(std::begin(a), std::end(a), 5) - a << std::endl;

    auto flag = std::binary_search(std::begin(a), std::end(a), 2);
    std::cout << "bsearch ret = " << flag << std::endl;
}

/**
 *  find查找
 * */
TEST(cxx_stl_algorithm, case8_find) {
    std::vector<int> vec {11 , 25, 30, 44, 50};
    std::vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        std::cout << "查找成功" << std::endl;
    } else {
        std::cout << "查找失败" << std::endl;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
