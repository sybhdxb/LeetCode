/**
******************************************************************************
* @file    88.c
* @author  sybhdxb
* @version V1.0
* @date    2021.04.05
* @brief   88
******************************************************************************
*/
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

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (nums1Size < m || nums2Size < n || nums1Size < m + n)
        return;

    nums1 += m;
    int i = 0;
    for (; i < n; i++)
    {
        *nums1++ = *nums2++;
    }
    nums1 -= (m + n);
    BubbleSort(nums1, n + m);
}

int cmp(int *a, int *b)
{
    // return *a - *b; //Up
    return *b - *a; //Dowm
}

void merge1(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = 0;
    for (; i != n; ++i)
    {
        nums1[m + i] = nums2[i];
    }
    qsort(nums1, nums1Size, sizeof(int), cmp);
}

int main(void)
{
    int array1[] = {100, 9, 20, 3, 88, 5, 3, 3, 3};
    int array2[] = {2, 0, 0, 5, 6};
    // merge(array1, 9, 6, array2, 5, 3);
    merge1(array1, 9, 6, array2, 5, 3);
    int i = 0;
    for (; i < 9; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}