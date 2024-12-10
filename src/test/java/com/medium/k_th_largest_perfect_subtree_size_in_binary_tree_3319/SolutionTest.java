package com.medium.k_th_largest_perfect_subtree_size_in_binary_tree_3319;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Test;

import java.util.Map;

class SolutionTest extends AbstractSolutionTest<AbstractSolution.TreeNode, Integer> {
    SolutionTest() {
        AbstractSolution.TreeNode treeNode = new AbstractSolution.TreeNode(true, "example 1", 5);
        treeNode.setLeft(3);
        treeNode.setRight(6);

        treeNode.getLeft().setLeft(5);
        treeNode.getLeft().setRight(2);

        treeNode.getRight().setLeft(5);
        treeNode.getRight().setRight(7);

        treeNode.getLeft().getLeft().setLeft(1);
        treeNode.getLeft().getLeft().setRight(8);

        treeNode.getRight().getLeft().setLeft(6);
        treeNode.getRight().getLeft().setRight(8);

        checkPoints = Map.ofEntries(Map.entry(treeNode, 2));

        AbstractSolution.TreeNode treeNode1 = new AbstractSolution.TreeNode(true, "example 2", 1);
        treeNode1.setLeft(2);
        treeNode1.setRight(3);

        treeNode1.getLeft().setLeft(4);
        treeNode1.getLeft().setRight(5);

        treeNode1.getRight().setLeft(6);
        treeNode1.getRight().setRight(7);

        AbstractSolution.TreeNode treeNode2 = new AbstractSolution.TreeNode(true, "example 3", 1);
        treeNode2.setLeft(2);
        treeNode2.setRight(3);

        treeNode2.getLeft().setRight(4);

        checkPoints = Map.ofEntries(
                Map.entry(treeNode, 2),
                Map.entry(treeNode1, 1),
                Map.entry(treeNode2, 3)
        );
    }
    @Test
    void testSolution() {
        for (Map.Entry<AbstractSolution.TreeNode, Integer> entry : checkPoints.entrySet()) {
            AbstractSolution.TreeNode treeNode = entry.getKey();
            Integer k = entry.getValue();

            System.out.println(treeNode.name);
            System.out.println(new Solution().kthLargestPerfectSubtree(treeNode, k));
        }
    }
}