/**
******************************************************************************
* @file    Sort.c
* @author  sybhdxb
* @version V1.0
* @date    2021.04.05
* @brief   Sort
******************************************************************************
*/

//https://www.cnblogs.com/onepixel/p/7674659.html

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SWOP(a, b) ((a) += (b), (b) = (a) - (b), (a) -= (b))
#define W(a, b) ((a) = (a) + (b) - ((b) = (a)))

void Swap(int *a, int *b)
{
    // *a = *a + *b;
    // *b = *a - *b;
    // *a = *a - *b;

    *a = *a + *b - (*b = *a);
}

void BubbleSort(int *nums1, int nums1Size)
{
    int i = 0, j = 0;
    for (i = 0; i < nums1Size - 1; i++)
    {
        for (j = 0; j < nums1Size - 1 - i; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                SWOP(nums1[j], nums1[j + 1]);
                // Swap(&nums1[j], &nums1[j + 1]);
                // W(nums1[j], nums1[j + 1]);
            }
        }
    }
}

int cmp_int(int *a, int *b)
{
    // return *a - *b; //Up
    return *b - *a; //Dowm
}

void Quicksort(int *nums1, int nums1Size)
{
    qsort(nums1, nums1Size, sizeof(int), cmp_int);
}

int main(void)
{

    return 0;
}