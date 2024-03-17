#include "headers.h"

class Solution {
public:
    static const int MASK1 = 1 << 7; // 1 << 7 == 1000 0000
    // 1 << 6 == 0100 0000
    // (1 << 7) + (1 << 6)  == 1100 0000
    static const int MASK2 = (1 << 7) + (1 << 6);

    /**
     * 判断首字节之后的字节，如果满足UTF-8编码，返回true；否则返回false
     * */
    bool isValid(int num) {
        // num && MASK2 获取前最高位两个比特位数据
        // (num & MASK2) == MASK1 判断最高两位是否是10，其实就是与MASK1是否相等
        return (num & MASK2) == MASK1;
    }

    /**
     * 根据首字节获取该字符由UTF-8编码时应该是多少字节
     *
     * @param num 首字节整数
     * @retval 字节数量
     * */
    int getBytes(int num) {
        if ((num & MASK1) == 0) { // 判断头字节和 MASK1的按位与运算结果是否为0
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0) { // num & mask得到当前比特位是0还是1
            n++;
            if (n > 4) { //如果大于4说明，不是UTF-8有效
                return -1;
            }
            mask >>= 1; // 掩码右移1位，当num & mask的时，就得到的是下一个比特位是0还是1
        }
        return n >= 2 ? n : -1;
    }

    bool validUtf8(vector<int> &data) {
        int m = data.size();
        int index = 0;
        while (index < m) {
            int num = data[index];
            int n = getBytes(num);
            if (n < 0 || index + n > m) {
                return false;
            }
            // 从第二个字节开始判断，最高两位是否是10
            for (int i = 1; i < n; i++) {
                if (!isValid(data[index + i])) { // 检查一个字节是否是有效的UTF-8编码的
                    return false;
                }
            }
            index += n;
        }
        return true;
    }
};

TEST(TTT, TTT) {
    Solution s;
//    [235,140,4]
//    vector<int> data = {235, 140, 4};
//    s.validUtf8(data);

    vector<int> data2 = {240, 162, 138, 147, 145};
    s.validUtf8(data2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
