/*
 * @Author: sybhdxb
 * @Date: 2021-10-22 15:19:13
 * @LastEditTime: 2021-10-22 16:39:27
 * @LastEditors: sybhdxb
 * @Description: 
 * @FilePath: \LeetCode\27.c
 * 这是一句废话，不用看
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int removeElement(int *nums, int numsSize, int val)
{
	int *p = nums;
	int *q = nums;
	int result = 0;

	if (numsSize < 1)
		return 0;

	for (; numsSize > 0; numsSize--)
	{
		if (*(q++) != val)
		{
			result++;
			*(p++) = *(q-1);
		}
	}
	return result;
}

int main(void)
{
	int Array[] = {1, 1, 1, 3, 4};
	int result = 0;

	result = removeElement(Array, 5, 1);
	system("pause");
	return 0;
}