#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "myTuringMachine.h"

void printTape1(int8_t* tape) {
    printf("Tape1内容: -1 ");
    // 打印指令部分
    while (*tape != -1) {
        printf("%d ", *tape);
        tape++;
    }
    printf("-1");
    tape++;
    // 打印数据部分
    if (*tape != -1) {
        printf(" ");
        while (*tape != -1) {
            printf("%d ", *tape);
            tape++;
        }
        printf("-1");
    }
    printf("\n");
}

void printTape2(int8_t* tape) {
    // 先移回开头
    while (*(tape-1) != -1) {
        tape--;
    }
    
    printf("Tape2内容: -1 ");
    while (*tape != -1) {
        printf("%d ", *tape);
        tape++;
    }
    printf("-1\n");
}

int main() {
    // 测试用例1：基本测试
    int8_t tape1_1[] = {-1, 0, 1, 0, -1, 1, 1, 0, -1};
    int8_t* tape2_1 = NULL;
    size_t tape2Size_1 = 0;
    
    printf("测试用例1:\n");
    printf("输入 ");
    printTape1(tape1_1 + 1);
    
    TuringMachine(tape1_1 + 1, &tape2_1, &tape2Size_1);
    
    printf("输出 ");
    printTape2(tape2_1);
    free(tape2_1);  // tape2_1已经在printTape2中移回开头，直接释放即可

    printf("tape2 大小: %zu\n\n", tape2Size_1);

    // 测试用例2：复杂指令
    int8_t tape1_2[] = {-1, 1, 0, 1, -1, 0, 1, 1, 0, 1, -1};
    int8_t* tape2_2 = NULL;
    size_t tape2Size_2 = 0;
    
    printf("测试用例2:\n");
    printf("输入 ");
    printTape1(tape1_2 + 1);
    
    TuringMachine(tape1_2 + 1, &tape2_2, &tape2Size_2);
    
    printf("输出 ");
    printTape2(tape2_2);
    free(tape2_2);  // tape2_2已经在printTape2中移回开头，直接释放即可

    printf("tape2 大小: %zu\n\n", tape2Size_2);

    // 测试用例3：最简单的情况
    int8_t tape1_3[] = {-1, 0, -1, 1, -1};
    int8_t* tape2_3 = NULL;
    size_t tape2Size_3 = 0;
    
    printf("测试用例3:\n");
    printf("输入 ");
    printTape1(tape1_3 + 1);
    
    TuringMachine(tape1_3 + 1, &tape2_3, &tape2Size_3);
    
    printf("输出 ");
    printTape2(tape2_3);
    free(tape2_3);  // tape2_3已经在printTape2中移回开头，直接释放即可

    printf("tape2 大小: %zu\n", tape2Size_3);

    return 0;
}