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
#include <malloc.h>

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

void merge1(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
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

//2.
int cmp(int *a, int *b)
{
    // return *a - *b; //Up
    return *b - *a; //Dowm
}

void merge2(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = 0;
    for (; i != n; ++i)
    {
        nums1[m + i] = nums2[i];
    }
    qsort(nums1, nums1Size, sizeof(int), cmp);
}

//3.The two arrays must be ordered，Double pointer
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

//4.Reverse double pointer
void merge4(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1, p2 = n - 1;
    int tail = m + n - 1;
    int cur;
    while (p1 >= 0 || p2 >= 0) {
        if (p1 == -1) {
            cur = nums2[p2--];
        } else if (p2 == -1) {
            cur = nums1[p1--];
        } else if (nums1[p1] > nums2[p2]) {
            cur = nums1[p1--];
        } else {
            cur = nums2[p2--];
        }
        nums1[tail--] = cur;
    }
}



int main(void)
{
    int array1[] = {1, 3, 4, 4, 10, 15, 23, 23, 33};
    int array2[] = {0, 0, 2, 5, 6};
    merge4(array1, 9, 6, array2, 5, 3);
    int i = 0;
    for (; i < 9; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}