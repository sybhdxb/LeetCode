/**
******************************************************************************
* @file    206.c
* @author  sybhdxb
* @version V1.0
* @date    2021.03.18
* @brief   206
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *NextNode = NULL;
    while (cur != NULL)
    {
        NextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = NextNode;
    }
    return prev;
}

int main(void)
{

    return 0;
}