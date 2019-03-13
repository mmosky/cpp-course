/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 */

#include "RandomWalk.h"

using namespace std;

int main()
{
    int T = 50000;
    printf("循环%d次, 下表项依次为\n", T);
    printf("城市规模\t失败概率\t平均路径\t失败路径\t成功路径\n");

    for (int N = 1; N <= 100; N++)
    {
        double failed, averLength, averFailedLength, averSucceededLength;
        repeatTest(N, T, failed, averLength,
                   averFailedLength, averSucceededLength);
        
        printf("%8d\t", N);
        printf("%7.4lf%%\t", failed * 100);
        printf("%8.4lf\t", averLength);
        printf("%8.4lf\t", averFailedLength);
        printf("%8.4lf\n", averSucceededLength);
    }
    return 0;
}

/* 累计用时: 30min */