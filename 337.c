/*
 * @lc app=leetcode.cn id=337 lang=c
 *
 * [337] 打家劫舍 III
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/**
 * 时间复杂度：O(n)。其中 n 为二叉树的节点个数。每个节点都会递归恰好一次。
 * 空间复杂度：O(n)。最坏情况下，二叉树是一条链，递归需要 O(n) 的栈空间。
 */

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct SubtreeStatus
{
	int selected;
	int notselected;
};

struct SubtreeStatus def(struct TreeNode *node)
{
	if (!node)
		return (struct SubtreeStatus){0, 0};

	struct SubtreeStatus l = def(node->left);
	struct SubtreeStatus r = def(node->right);

	int selected = node->val + l.notselected + r.notselected;
	int notselected = fmax(l.selected, l.notselected) + fmax(r.selected, r.notselected);
	return (struct SubtreeStatus){selected, notselected};
};

int rob(struct TreeNode *root)
{
	struct SubtreeStatus rootStatus = def(root);
	return fmax(rootStatus.selected, rootStatus.notselected);
}
// @lc code=end

int main(void)
{

	system("pause");
	return 0;
}
