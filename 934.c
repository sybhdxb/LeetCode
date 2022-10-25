/**
******************************************************************************
* @file    934.c
* @author  Howard
* @version V1.0
* @date    2022.10.25
* @brief   934
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int shortestBridge(int grid[2][2], int gridSize)
{
	int n = gridSize;
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	int *island = (int *)malloc(sizeof(int) * n * n);
	int *queue = (int *)malloc(sizeof(int) * n * n);
	int head = 0, tail = 0; //广度优先，搜索1层

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
			{
				queue[tail++] = i * n + j;
				grid[i][j] = -1;
				int islandSize = 0;
				while (head != tail)
				{
					int x = queue[head] / n;
					int y = queue[head] % n;
					island[islandSize++] = queue[head];
					head++;
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dirs[k][0];
						int ny = y + dirs[k][1];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) //如果上下左右有1，记录下来
						{
							queue[tail++] = nx * n + ny;
							grid[nx][ny] = -1;
						}
					}
				}
				head = tail = 0;
				for (int i = 0; i < islandSize; i++)
				{
					queue[tail++] = island[i];
				}
				int step = 0;
				while (head != tail)
				{
					int sz = tail - head;
					for (int i = 0; i < sz; i++)
					{
						int x = queue[head] / n;
						int y = queue[head] % n;
						head++;
						for (int k = 0; k < 4; k++)
						{
							int nx = x + dirs[k][0];
							int ny = y + dirs[k][1];
							if (nx >= 0 && ny >= 0 && nx < n && ny < n)
							{
								if (grid[nx][ny] == 0)
								{
									queue[tail++] = nx * n + ny;
									grid[nx][ny] = -1;
								}
								else if (grid[nx][ny] == 1)
								{
									free(queue);
									free(island);
									return step;
								}
							}
						}
					}
					step++;
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	int Array[2][2] = {{1, 0}, {0, 1}};
	printf(":%d\r\n", shortestBridge(Array, 2));

	system("pause");
	return 0;
}
