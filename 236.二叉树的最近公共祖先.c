/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 * 时间复杂度：O(n)，其中 n 为二叉树的节点个数。
 * 空间复杂度：O(n)。最坏情况下，二叉树退化成一条链，因此递归需要 O(n) 的栈空间。
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
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	/*
		当前节点为空节点、为p、为q，则返回当前节点
	*/
	if (NULL == root || root == p || root == q)
		return root;

	/*
		开始递归
	*/
	struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

	/*
		左右子树都找到，返回当前节点
	*/
	if (NULL != left && NULL != right)
		return root;

	/*
		只有一个（左子树或右子树）找到或都没有找到，返回找到的节点或空节点
	*/
	return NULL == left ? right : left;
}
// @lc code=end

int main(void)
{
	system("pause");
	return 0;
}