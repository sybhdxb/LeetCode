/**
******************************************************************************
* @file    862.cpp
* @author  Howard
* @version V1.0
* @date    2022.10.26
* @brief
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	int shortestSubarray(vector<int> &nums, int k)
	{
		int n = nums.size(), ans = n + 1;
		long s[n + 1];
		s[0] = 0L;
		for (int i = 0; i < n; ++i)
			s[i + 1] = s[i] + nums[i]; // 计算前缀和
		deque<int> q;
		for (int i = 0; i <= n; ++i)
		{
			long cur_s = s[i];
			while (!q.empty() && cur_s - s[q.front()] >= k)
			{
				ans = min(ans, i - q.front());
				q.pop_front(); // 优化一
			}
			while (!q.empty() && s[q.back()] >= cur_s)
				q.pop_back(); // 优化二
			q.push_back(i);
		}
		return ans > n ? -1 : ans;
	}
};

int main(int argc, char *argv[])
{
	Solution temp;
	vector<int> Array[] = {{1}, {1, 2}, {2, -1, 2}};
	cout << temp.shortestSubarray(Array[1], 4) << endl;
	system("pause");
	return 0;
}