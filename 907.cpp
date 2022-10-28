/**
******************************************************************************
* @file    907.cpp
* @author  Howard
* @version V1.0
* @date    2022.10.28
* @brief
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution
{
	const int MOD = 1e9 + 7;

public:
	int sumSubarrayMins1(vector<int> &arr)
	{
		int n = arr.size();
		// 左边界 left[i] 为左侧严格小于 arr[i] 的最近元素位置（不存在时为 -1）
		vector<int> left(n, -1);
		stack<int> st;
		for (int i = 0; i < n; ++i)
		{
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop(); // 移除无用数据
			if (!st.empty())
				left[i] = st.top();
			st.push(i);
		}

		// 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
		vector<int> right(n, n);
		while (!st.empty())
			st.pop();
		for (int i = n - 1; i >= 0; --i)
		{
			while (!st.empty() && arr[st.top()] > arr[i])
				st.pop(); // 移除无用数据
			if (!st.empty())
				right[i] = st.top();
			st.push(i);
		}

		long ans = 0L;
		for (int i = 0; i < n; ++i)
			ans += (long)arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
		return ans % MOD;
	}

	int sumSubarrayMins2(vector<int> &arr)
	{
		int n = arr.size();
		vector<int> left(n, -1), right(n, n);
		stack<int> st;
		for (int i = 0; i < n; ++i)
		{
			while (!st.empty() && arr[st.top()] >= arr[i])
			{
				right[st.top()] = i; // i 恰好是栈顶的右边界
				st.pop();
			}
			if (!st.empty())
				left[i] = st.top();
			st.push(i);
		}

		long ans = 0L;
		for (int i = 0; i < n; ++i)
			ans += (long)arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
		return ans % MOD;
	}

	int sumSubarrayMins(vector<int> &arr)
	{
		long ans = 0L;
		arr.push_back(-1);
		stack<int> st;
		st.push(-1); // 哨兵
		for (int r = 0; r < arr.size(); ++r)
		{
			while (st.size() > 1 && arr[st.top()] >= arr[r])
			{
				int i = st.top();
				st.pop();
				ans += (long)arr[i] * (i - st.top()) * (r - i); // 累加贡献
			}
			st.push(r);
		}
		return ans % MOD;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> Array[] = {{11, 81, 94, 43, 3}};
	cout << s.sumSubarrayMins(Array[0]) << endl;
	system("pause");
	return 0;
}