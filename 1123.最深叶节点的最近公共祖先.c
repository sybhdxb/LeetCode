/*
 * @lc app=leetcode.cn id=1123 lang=c
 *
 * [1123] 最深叶节点的最近公共祖先
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
struct Pair
{
	struct TreeNode *node;
	int depth;
};

struct Pair f(struct TreeNode *root)
{
	if (root == NULL)
	{
		return (struct Pair){NULL, 0};
	}

	struct Pair left = f(root->left);
	struct Pair right = f(root->right);

	if (left.depth > right.depth)
	{
		return (struct Pair){left.node, left.depth + 1};
	}
	if (left.depth < right.depth)
	{
		return (struct Pair){right.node, right.depth + 1};
	}
	return (struct Pair){root, left.depth + 1};
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root)
{
	return f(root).node;
}
// @lc code=end

int main(void)
{
	system("pause");
	return 0;
}
