/**
******************************************************************************
* @file    1822.c
* @author  Howard
* @version V1.0
* @date    2022.10.27
* @brief
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int arraySign(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return 0;

	bool sign = true;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == 0)
			return 0;
		else if (nums[i] < 0)
			sign = !sign;
	}
	return sign ? 1 : -1;
}

int main(int argc, char *argv[])
{
	int array[] = {-1, -2, -3, -4, 3, 2, 1};
	printf("%d\r\n", arraySign(array, sizeof(array) / sizeof(int)));
	system("pause");
	return 0;
}