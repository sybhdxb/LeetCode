/**
******************************************************************************
* @file    92_Reverse_Linked_List_2.c
* @author  sybhdxb
* @version V1.0
* @date    2021.03.18
* @brief   92_Reverse_Linked_List_2
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//https://leetcode-cn.com/problems/reverse-linked-list-ii/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    if (left == right)
        return head; // 不用管的情况

    struct ListNode h = {0, head}; //设置一个头节点,处理left=1的情况
    struct ListNode *p = &h;
    struct ListNode *tail;
    for (int i = 1; i <= right; i++)
    {
        if (i < left) // p指向第n-1个节点位置
            p = p->next;
        else if (i == left) // tail指向第left个节点，这个节点反转后处在反转部分的最后一个
            tail = p->next;
        else
        { //每次将tail后面一个节点拿出来，放在p后面
            struct ListNode *item = tail->next;
            tail->next = tail->next->next;
            item->next = p->next;
            p->next = item;
        }
    }
    return h.next;
}

int main(void)
{

    return 0;
}