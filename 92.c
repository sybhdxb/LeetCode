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
        return head; // ���ùܵ����

    struct ListNode h = {0, head}; //����һ��ͷ�ڵ�,����left=1�����
    struct ListNode *p = &h;
    struct ListNode *tail;
    for (int i = 1; i <= right; i++)
    {
        if (i < left) // pָ���n-1���ڵ�λ��
            p = p->next;
        else if (i == left) // tailָ���left���ڵ㣬����ڵ㷴ת���ڷ�ת���ֵ����һ��
            tail = p->next;
        else
        { //ÿ�ν�tail����һ���ڵ��ó���������p����
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