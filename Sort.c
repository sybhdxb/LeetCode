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


//1.
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

//2.
int cmp_int(int *a, int *b)
{
    // return *a - *b; //Up
    return *b - *a; //Dowm
}

void Quicksort(int *nums1, int nums1Size)
{
    qsort(nums1, nums1Size, sizeof(int), cmp_int);
}

//3.The two arrays must be ordered
void merge3(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int p1 = 0, p2 = 0;
    // int sorted[m + n];
    int *sorted = (int *)malloc(nums1Size * 4);
    int cur;
    while (p1 < m || p2 < n)
    {
        if (p1 == m)
        {
            cur = nums2[p2++];
        }
        else if (p2 == n)
        {
            cur = nums1[p1++];
        }
        else if (nums1[p1] < nums2[p2])
        {
            cur = nums1[p1++];
        }
        else
        {
            cur = nums2[p2++];
        }
        *sorted++ = cur;
    }
    sorted -= (m + n);
    int i = 0;
    for (; i != m + n; ++i)
    {
        nums1[i] = sorted[i];
    }
    free(sorted);
}



int main(void)
{

    return 0;
}