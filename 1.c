/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] Two Sum
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (ret[0] = 0; ret[0] < numsSize; ++ret[0])
    {
        for (ret[1] = ret[0] + 1; ret[1] < numsSize; ++ret[1])
        {
            if (nums[ret[0]] + nums[ret[1]] == target)
            {
                return ret;
            }
        }
    }
    return ret;
}
// @lc code=end

int main(void)
{
    int nums[4] = {2, 7, 11, 15};
    int returnSize;
    int *re;
    re = twoSum((int *)nums, 4, 9, &returnSize);
    return 0;
}