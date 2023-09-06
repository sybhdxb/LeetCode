/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

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
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	if (NULL == root || root == p || root == q)
		return root;

	struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

	if (NULL != left && NULL != right)
		return root;

	return NULL == left ? right : left;
}
// @lc code=end

int main(void)
{
	system("pause");
	return 0;
}