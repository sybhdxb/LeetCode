<!--
 * @Author: sybhdxb
 * @Date: 2021-10-22 14:19:46
 * @LastEditTime: 2021-10-22 15:09:37
 * @LastEditors: Howard
 * @Description:
 * @FilePath: \LeetCode\README.md
 * 这是一句废话，不用看
-->

# LeetCode

**由 vscode 插件 LeetCode 创建用例，并测试通过的试题**

# 刷题顺序

> 目前 LeetCode 题量很大，怎么刷比较好？
> https://www.zhihu.com/question/268425862/answer/2853273199

|             题目             | 难度 |                                 链接                                  |
| :--------------------------: | :--: | :-------------------------------------------------------------------: |
|         1. 两数之和          | 简单 |                                                                       |
|  26. 删除有序数组中的重复项  | 简单 | https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/ |
|         27. 移除元素         | 简单 |           https://leetcode-cn.com/problems/remove-element/            |
| 34. 在排序数组中查找元素的第一个和最后一个位置 | 中等 | https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/ |
|         61. 旋转链表         | 中等 |           https://leetcode.cn/problems/rotate-list/                   |
|     88. 合并两个有序数组     | 简单  |      https://leetcode.cn/problems/merge-sorted-array/                 |
|        92. 反转链表 2        |      |                                                                       |
|     201. 数字范围按位与      |  中等 |  https://leetcode.cn/problems/bitwise-and-of-numbers-range/          |
|        206. 反转链表         | 简单  |     https://leetcode.cn/problems/reverse-linked-list/               |
|  235. 二叉搜索树的最近公共祖先 | 中等 | https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/ |
|   236. 二叉树的最近公共祖先   | 中等 | https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/ |
|    485. 最大连续 1 的个数    | 简单 |    https://leetcode.cn/problems/max-consecutive-ones/description/     |
|        495. 提莫攻击         | 简单 |             https://leetcode.cn/problems/teemo-attacking/             |
| 862. 和至少为 K 的最短子数组 | 困难 |  https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/  |
|   907. 子数组的最小值之和    | 简单 |        https://leetcode.cn/problems/sum-of-subarray-minimums/         |
|        915. 分割数组         | 中等 | https://leetcode.cn/problems/partition-array-into-disjoint-intervals/ |
|        934. 最短的桥         | 中等 |             https://leetcode.cn/problems/shortest-bridge/             |
| 1123. 最深叶节点的最近公共祖先 | 中等 | https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves |
|      1603. 设计停车系统      |      |                                                                       |
|     1768. 交替合并字符串     | 简单 |        https://leetcode.cn/problems/merge-strings-alternately/        |
|    1822. 数组元素积的符号    | 简单 |     https://leetcode.cn/problems/sign-of-the-product-of-an-array/     |
|    2594. 修车的最少时间      | 中等 |      https://leetcode.cn/problems/minimum-time-to-repair-cars/      |

> Array2ListNode 数组转链表

> Sort 排序

# windows环境配置

## VSCode
### LeetCode插件

```json
  "leetcode.filePath": {
    "default": {
      "folder": "",
      "filename": "${id}.${ext}"	//默认有中文名，无法在vscode中debug，所以删除中文，只保留题目序号
    }
  },
```

### Code Runner

不好使。