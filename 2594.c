/*
 * @lc app=leetcode.cn id=2594 lang=c
 *
 * [2594] 修车的最少时间
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/**
 * 时间复杂度：O(nlog(mc^2))，其中 n 为 ranks 的长度，m=min⁡(ranks)，c=cars。
 * 空间复杂度：O(1)。仅用到若干外部变量。
 */

// @lc code=start
int min_array(int *array, int size)
{
	int min = array[size - 1];
	while (--size)
	{
		min = array[size - 1] < min ? array[size - 1] : min;
	}
	return min;
}

long long repairCars(int *ranks, int ranksSize, int cars)
{
	int min_r = min_array(ranks, ranksSize);
	long long left = 0, right = 1LL * min_r * cars * cars;
	long long mid = 0, sum = 0;
	int i = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		sum = 0;
		for (i = 0; i < ranksSize; i++)
		{
			sum += sqrt(mid / ranks[i]);
		}
		if (sum >= cars)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

// @lc code=end

int main(void)
{
	int a[] = {4, 2, 3, 1};
	printf("%d\r\n", min_array(a, 4));
	repairCars((int *)a, 4, 10);
	system("pause");
	return 0;
}
