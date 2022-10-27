/**
******************************************************************************
* @file    1822.cpp
* @author  Howard
* @version V1.0
* @date    2022.10.27
* @brief
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int arraySign(vector<int> &nums)
	{
		int sign = 1;
		for (auto num : nums)
		{
			if (num == 0)
				return 0;
			if (num < 0)
				sign = -sign;
		}
		return sign;
	}
};
int main(int argc, char *argv[])
{
	Solution s;
	vector<int> Array[] = {{1, 1, 1, 0, 6, 12}};
	cout << s.arraySign(Array[0]) << endl;
	system("pause");
	return 0;
}