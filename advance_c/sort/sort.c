#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    int x;
    int y;
};

//按照x从小到大排序，当x相等时按y从大到小排序
int Comp(const void* p1,const void* p2) {
    struct Node* n1 = (struct Node*)p1;
    struct Node* n2 = (struct Node*)p2;
    if(n1->x != n2->x) {
        return n1->x - n2->x;
    }
    return n2->y - n1->y;
};

int main(int argc, char **argv) {
    size_t size = 5;
    struct Node* nodes = (struct Node*) malloc(size * sizeof (struct Node));
    if (nodes == NULL) {
        return -1;
    }
    (void)memset(nodes, 0, size * sizeof(struct Node));
    for (int i = 0; i < size; ++i) {
        struct Node* tmp = nodes + i;
        tmp->x = i;
        tmp->y = i * 3;
    }
    // 排序
    qsort(nodes, size, sizeof(struct Node), Comp);
    for (int i = 0; i < size; ++i) {
        struct Node* tmp = nodes + i;
        printf("x : %d , y: %d \n", tmp->x, tmp->y);
    }
    free(nodes);
    return 0;
}


