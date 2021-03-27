/**
******************************************************************************
* @file    arry2listnode.c
* @author  sybhdxb
* @version V1.0
* @date    2021.03.27
* @brief   arry2listnode
******************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
};

void print(struct ListNode* h)
{
    struct ListNode* p = h->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct ListNode* CreateList(int array[], int n)
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
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = array[i-1];
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L;
}

int main()
{
    struct ListNode* Head = NULL;
    int array[] = {1, 2, 3, 4, 5};

    Head = CreateList(array, sizeof(array)/sizeof(array[0]));

    print(Head);
    printf("\n\n");
    system("pause");
    return 0;
}

