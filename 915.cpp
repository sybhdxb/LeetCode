/**
******************************************************************************
* @file    915.cpp
* @author  Howard
* @version V1.0
* @date    2022.10.24
* @brief   915
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int partitionDisjoint(vector<int> &nums)
	{
		if(nums.empty())
			return 0;

		int n = nums.size();
		int leftMax = nums[0], leftPos = 0, curMax = nums[0];
		for (int i = 1; i < n - 1; ++i)
		{
			curMax = max(curMax, nums[i]);
			if (nums[i] < leftMax)
			{
				leftMax = curMax;
				leftPos = i;
			}
		}
		return leftPos + 1;
	}
};

int main()
{
	Solution temp;
	vector<int> Array[] = {{1, 1, 1, 0, 6, 12}};
	cout << temp.partitionDisjoint(Array[0]) << endl;
	return 0;
}
