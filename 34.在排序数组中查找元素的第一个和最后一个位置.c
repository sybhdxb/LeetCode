/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/**
 * 时间复杂度：O(logn)，其中n为nums的长度。
 * 空间复杂度：O(1),仅用到若干额外变量。
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * 二分法查找
 */

/**
 * 闭区间
 */
int lower_bound(int *nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1; // 闭区间[left, right]
	int mid = 0;

	while (left <= right) // 区间不为空
	{
		/**
		 * 循环不变量：
		 * nums[left-1]<target
		 * nums[right+1]>=target
		 */
		mid = (int)(right + left) / 2;
		if (nums[mid] < target)
			left = mid + 1; // 范围缩小到[mid+1, right]
		else
			right = mid - 1; // 范围缩小到[left, mid-1]
	}
	return left; // 或 right+1
}

/**
 * 左闭右开区间
 */
int lower_bound2(int *nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize; // 左闭右开区间[left, right)
	int mid = 0;

	while (left < right) // 区间不为空
	{
		/**
		 * 循环不变量：
		 * nums[left-1]<target
		 * nums[right+1]>=target
		 */
		mid = (int)(right + left) / 2;
		if (nums[mid] < target)
			left = mid + 1; // 范围缩小到[mid+1, right)
		else
			right = mid; // 范围缩小到[left, mid)
	}
	return left; // 或 right
}

/**
 * 开区间
 */
int lower_bound3(int *nums, int numsSize, int target)
{
	int left = -1;
	int right = numsSize; // 开区间(left, right)
	int mid = 0;

	while (left + 1 < right) // 区间不为空
	{
		/**
		 * 循环不变量：
		 * nums[left-1]<target
		 * nums[right+1]>=target
		 */
		mid = (int)(right + left) / 2;
		if (nums[mid] < target)
			left = mid; // 范围缩小到(mid, right)
		else
			right = mid; // 范围缩小到(left, mid)
	}
	return left; // 或 left+1
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int start = 0, end = 0;
	int *ans = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	start = lower_bound(nums, numsSize, target);
	if (start == numsSize || nums[start] != target)
	{
		start = -1;
		end = -1;
	}
	else
		end = lower_bound(nums, numsSize, target + 1) - 1;

	ans[0] = start;
	ans[1] = end;
	return ans;
}
// @lc code=end

int main(void)
{
	int array[] = {5,7,7,8,8,10};
	int *a2;
	int *s;
	a2 = searchRange((int *)array, 6, 8, s);
	printf("[%d, %d]", *a2, *(a2+1));
	system("pause");
	return 0;
}
