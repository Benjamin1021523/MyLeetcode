package com.medium.k_th_largest_perfect_subtree_size_in_binary_tree_3319;

import java.util.*;

public class Solution extends AbstractSolution {
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        result = new TreeMap<>(Comparator.reverseOrder());
        perfectTreeCount = 0;

        countTreeNodesDepth(root);

        if (k > perfectTreeCount)
            return -1;

        for (Integer key : result.keySet()) {
            k -= result.get(key);
            if (k <= 0) {
                return (int) Math.pow(2, key) - 1;
            }
        }

        return -1;
    }

    private SortedMap<Integer, Integer> result;
    private int perfectTreeCount;
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

        return nowDepth;
    }
}
