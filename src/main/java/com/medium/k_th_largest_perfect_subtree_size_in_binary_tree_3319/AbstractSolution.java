package com.medium.k_th_largest_perfect_subtree_size_in_binary_tree_3319;

public abstract class AbstractSolution {
    abstract int kthLargestPerfectSubtree(TreeNode root, int k);

    public static class TreeNode {
        String path;
        String name;
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(boolean isRoot, String rootName, int val) {
            if (isRoot) {
                path = "*";
                name = rootName;
                System.out.println(path + ": " + val);
            }
        }

        TreeNode(int val) {
            this(false, "", val);
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        public TreeNode getLeft() {
            return left;
        }

        public TreeNode setLeft(int leftVal) {
            return setLeft(new TreeNode(leftVal));
        }

        private TreeNode setLeft(TreeNode left) {
            this.left = left;
            if (left != null) {
                left.path = this.path + "-l";
                System.out.println(this.left.path + ": " + left.val);
            }
            return left;
        }

        public TreeNode getRight() {
            return right;
        }

        public TreeNode setRight(int rightVal) {
            return setRight(new TreeNode(rightVal));
        }

        private TreeNode setRight(TreeNode right) {
            this.right = right;
            if (right != null) {
                right.path = this.path + "-r";
                System.out.println(this.right.path + ": " + right.val);
            }
            return right;
        }
    }
}
