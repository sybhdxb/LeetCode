/*
 * @lc app=leetcode.cn id=495 lang=c
 *
 * [495] 提莫攻击
 */
#include <stdio.h>
// @lc code=start

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
	int timecnt = 0, index = 0;
	if(timeSeries == NULL || timeSeriesSize <= 0)
		return -1;

	if(timeSeriesSize == 1)
		return duration;

	for (; index < timeSeriesSize - 1; ++index)
	{
		timecnt += (timeSeries[index] + duration < timeSeries[index + 1] ? duration : timeSeries[index + 1] - timeSeries[index]);
	}
	timecnt += duration;
	return timecnt;
}
// @lc code=end

