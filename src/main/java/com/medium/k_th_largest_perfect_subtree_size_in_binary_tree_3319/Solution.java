package com.medium.k_th_largest_perfect_subtree_size_in_binary_tree_3319;

import java.util.*;

public class Solution extends AbstractSolution {
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        countTreeNodesDepth(root);

        if (k > perfectTreeCount)
            return -1;

        for (int depth = nowMaxDepth; depth > 0; depth--) {
            k -= result.get(depth);
            if (k <= 0) {
                return (int) Math.pow(2, depth) - 1;
            }
        }

        return -1;
    }

    private final Map<Integer, Integer> result = new HashMap<>();
    private int nowMaxDepth = -1;
    private int perfectTreeCount = 0;
    private int countTreeNodesDepth(TreeNode root) {
        if (root == null)
            return 0;

        int leftDepth = countTreeNodesDepth(root.left);
        int rightDepth = countTreeNodesDepth(root.right);
        if (leftDepth == -1 || leftDepth != rightDepth)
            return -1;
        int nowDepth = leftDepth + 1;

        result.merge(nowDepth, 1, Integer::sum);
        perfectTreeCount++;
        if (nowDepth > nowMaxDepth) {
            nowMaxDepth = nowDepth;
        }

        return nowDepth;
    }
}
