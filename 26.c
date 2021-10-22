/*
 * @Author: sybhdxb
 * @Date: 2021-10-22 14:35:26
 * @LastEditTime: 2021-10-22 15:06:24
 * @LastEditors: sybhdxb
 * @Description: 
 * @FilePath: \LeetCode\26.c
 * 这是一句废话，不用看
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int removeDuplicates(int *nums, int numsSize)
{
	int *p = nums;
	int *q = nums;
	int result = 1;

	if (numsSize <= 0)
		return 0;

	for (; numsSize > 1; numsSize--)
	{
		if (*p != *(++q))
		{
			result++;
			*(++p) = *q;
		}
	}
	return result;
}

int main(void)
{
	int Array[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

	int res = 0;
	res = removeDuplicates(Array, 10);
	system("pause");
	return 0;
}