/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start


int findMaxConsecutiveOnes(int* nums, int numsSize){
	int max = 0, cnt = 0;
	if(numsSize <= 0)
		return -1;
	
	do
	{
		if(nums[numsSize-1] == 1)
			++cnt;
		else
			cnt = 0;
		if(cnt >= max)
			max = cnt;
	} while (--numsSize);
	return max;
}
// @lc code=end

