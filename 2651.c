/*
 * @lc app=leetcode.cn id=2651 lang=c
 *
 * [2651] 计算列车到站时间
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/**
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

// @lc code=start
int findDelayedArrivalTime(int arrivalTime, int delayedTime)
{
	return (arrivalTime + delayedTime) % 24;
}
// @lc code=end

int main(void)
{

	system("pause");
	return 0;
}