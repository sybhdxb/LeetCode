/**
******************************************************************************
* @file    1603.c
* @author  Howard
* @version V1.0
* @date    2022.10.23
* @brief   1603
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

char *mergeAlternately(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i = 0, j = 0;
    char *string = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    while (i < len1 || i < len2)
    {
        i < len1 ? string[j++] = word1[i] : 0;
        i < len2 ? string[j++] = word2[i] : 0;
        ++i;
    }
    string[j] = '\0';
    return string;
}

int main(void)
{
    printf("%s\r\n", mergeAlternately("123", "45678"));
    
	system("pause");
    return 0;
}
