/**
******************************************************************************
* @file    61.c
* @author  sybhdxb
* @version V1.0
* @date    2021.03.27
* @brief   61
******************************************************************************
*/
//https://leetcode-cn.com/problems/rotate-list/submissions/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
};

void print(struct ListNode *h)
{
    struct ListNode *p = h;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

struct ListNode *CreateList(int array[], int n)
{
    struct ListNode *L, *p, *q;
    int i;
    L = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!L)
        return 0;
    L->next = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = array[i - 1];
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L->next;
}

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int num = 1;
    struct ListNode *p = head, *q;

    while (p->next != NULL)
    {
        num++;
        p = p->next;
    }
    k = num - k % num;
    if (k == 0)
        return head;
    p->next = head;

    while (k--)
    {
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    return q;
}

int main()
{
    struct ListNode *Head = NULL;
    struct ListNode *Res = NULL;
    int array[] = {1, 2, 3, 4, 5};

    Head = CreateList(array, sizeof(array) / sizeof(array[0]));

    print(Head);
    printf("\n\n");

    Res = rotateRight(Head, 1);

    print(Res);
    printf("\n\n");
    system("pause");
    return 0;
}
