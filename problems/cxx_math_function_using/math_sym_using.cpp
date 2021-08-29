#include "headers.h"

#define MEMBER_SIZE 7

int compar(const void *a, const void *b) {
  int *aa = (int *)a;
  int *bb = (int *)b;
  if (*aa > *bb) {
    return 1;
  } else if (*aa == *bb) {
    return 0;
  }
  return -1;
}

TEST(math_sym_using, case1) {
    int base[MEMBER_SIZE] = {3, 102, 5, -2, 98, 52, 18};
    int i = 0;
    for (i = 0; i < MEMBER_SIZE; i++) {
        cout << setbase(10) << base[i] << " ";
    }
    cout << endl;

    qsort(base, MEMBER_SIZE ,sizeof(int), compar);

    for (i = 0; i < MEMBER_SIZE; i++) {
        cout << setbase(10) << base[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
