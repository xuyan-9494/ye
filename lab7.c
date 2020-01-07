#include <stdio.h>
#include <stdlib.h>

// argc为输入的参数的个数，argv[]为参数数组
int main(int argc, const char * argv[]) {
    double* min = NULL;
    // 因为参数包括执行程序本身，所以需要从第1个开始取
    for (int i = 1; i < argc; i++) {
        // 定义一个double类型的指针，申请新的内存地址
        double *num = (double*) malloc(sizeof(double));
        // 将输入的字符串转为double数据
        *num = atof(argv[i]);
        // 如果min为NULL，说明当前还没有赋值，则直接将num赋值给min
        if (min == NULL) {
            min = num;
        }
        else {
            // 如果min大于当前数据，则释放min的内存，将num赋值给min
            if (*min > *num) {
                free(min);
                min = num;
            }
            // 否则释放num的内存
            else {
                free(num);
            }
        }
    }
    if (min == NULL) {
        printf("您未输入任何有效的数据！\n");
    }
    else {
        printf("您输入的数据的最小值为: %f\n", *min);
        // 释放min的内存
        free(min);
    }
    return 0;
}
