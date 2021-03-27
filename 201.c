/**
******************************************************************************
* @file    201.c
* @author  sybhdxb
* @version V1.0
* @date    2021.03.27
* @brief   201
******************************************************************************
*/
// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define Power(n) (1 << n)

int rangeBitwiseAnd(int left, int right)
{
    // int i = 0;
    // while (left != right)
    // {
    //     left >>= 1;
    //     right >>= 1;
    //     i++;
    // }
    // return left << i;

    while (left < right)
    {
        // 抹去最右边的 1
        right &= (right - 1);
    }
    return right;
}

int main(void)
{
    printf("%d\n", rangeBitwiseAnd(2, 3));
    system("pause");
    return 0;
}
