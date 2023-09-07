/*
 * @lc app=leetcode.cn id=235 lang=c
 *
 * [235] 二叉搜索树的最近公共祖先
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 * 时间复杂度：O(n)，其中 n 为二叉搜索树的节点个数。
 * 空间复杂度：O(n)。最坏情况下，二叉搜索树退化成一条链（注意题目没有保证它是平衡树），因此递归需要 O(n) 的栈空间。
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
	int i = root->val;

	/**
	 * p和q都在左边
	*/
	if(p->val < i && q->val < i)
		return lowestCommonAncestor(root->left, p, q);
	
	/**
	 * p和q都在右边
	*/
	if(p->val > i && q->val > i)
		return lowestCommonAncestor(root->right, p, q);
	
	/**
	 * p和q分别在左右子树，或当前节点是p或q
	*/
	return root;
}
// @lc code=end

int main(void)
{
	system("pause");
	return 0;
}
