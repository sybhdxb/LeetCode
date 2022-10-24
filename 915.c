/**
******************************************************************************
* @file    915.c
* @author  Howard
* @version V1.0
* @date    2022.10.24
* @brief   915
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int partitionDisjoint(int *nums, int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}

	// int minRight[numsSize];
	// minRight[numsSize - 1] = nums[numsSize - 1];
	// for (int i = numsSize - 2; i >= 0; i--)
	// {
	// 	minRight[i] = MIN(nums[i], minRight[i + 1]);
	// }

	// int maxLeft = 0;
	// for (int i = 0; i < numsSize - 1; i++)
	// {
	// 	maxLeft = MAX(maxLeft, nums[i]);
	// 	if (maxLeft <= minRight[i + 1])
	// 	{
	// 		return i + 1;
	// 	}
	// }
	// return numsSize - 1;

	int leftMax = nums[0], leftPos = 0, curMax = nums[0];
	for (int i = 1; i < numsSize - 1; ++i)
	{
		curMax = MAX(curMax, nums[i]);
		if (nums[i] < leftMax)
		{
			leftMax = curMax;
			leftPos = i;
		}
	}
	return leftPos + 1;
}

int main(void)
{
	int Array[] = {1, 1, 1, 0, 6, 12};
	printf("%d\r\n", partitionDisjoint(Array, sizeof(Array) / sizeof(int)));

	system("pause");
	return 0;
}
