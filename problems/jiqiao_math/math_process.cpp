#include <iostream>
#include <math.h>

int main(int argc, char **argv) {
    // 平方
    int a = pow(4, 2); // 4的2次方，即4*4=16
    std::cout << a << std::endl;

    // 开平方
    int b = pow(4, 0.5); // 4的1/2次方， 也就是4开2次根等于2
    std::cout << b << std::endl;
    int c = sqrt(4);
    std::cout << c << std::endl;

    // 整数绝对值
    int d = abs(-4); // -4的绝对值等于正4
    std::cout << d << std::endl;

    // 浮点数绝对值
    double e = fabs(b - c);
    std::cout << e << std::endl;
    double f = fabs(b - c - 0.5);
    std::cout << f << std::endl;
    return 0;
}
