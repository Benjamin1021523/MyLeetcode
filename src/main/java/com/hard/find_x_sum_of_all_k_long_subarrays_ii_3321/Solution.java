package com.hard.find_x_sum_of_all_k_long_subarrays_ii_3321;

import java.util.*;

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/solutions/5911343/java-implementation-treeset-map
class Solution extends AbstractSolution {
    // 計算某K個數的總和
    long sum = 0;
    HashMap<Integer, Integer> map = new HashMap<>();
    TreeSet<Pair> large = new TreeSet<>();
    TreeSet<Pair> small = new TreeSet<>();

    public void add(int num) {
        update(num, 1);
    }

    public void remove(int num) {
        update(num, -1);
    }

    private void update(int num, int v) {
        // 確認該數字出現次數
        int freq = map.getOrDefault(num, 0);

        Pair before = new Pair(num, freq);
        Pair after = new Pair(num, freq + v);

        // 是否包含在目前前k個出現次數較多的集合中
        if (large.contains(before)) {
            // 移除原本的記錄
            large.remove(before);
            // 更新總和
            sum += (long) v * num;
            // 更新num目前的記錄(新增或移除會是+1或-1)
            map.put(num, freq + v);
            large.add(after);

        } else if (small.contains(before)) {
            small.remove(before);
            map.put(num, freq + v);
            small.add(after);
        }
    }

    public void equilibrium(int x) {
        // 當較大的數量不足要求時，要取較小的當中最大的加入，直到數量足夠
        while (large.size() < x && !small.isEmpty()) {
            Pair second = small.last();
            large.add(second);
            sum += second.getTotal();
            small.remove(second);
        }

        if (small.isEmpty()) {
            return;
        }

        // 檢查最小的最大和最大的最小之間的排序，判斷是否要交換
        while (true) {
            Pair first = large.first();
            Pair second = small.last();

            // first次數較少/次數相同但數值較小時
            if (first.compareTo(second) < 0) {
                large.remove(first);
                small.remove(second);
                large.add(second);
                small.add(first);
                sum -= first.getTotal();
                sum += second.getTotal();
            } else {
                break;
            }
        }
    }

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] ans = new long[n - k + 1];
        // 初始化
        for (int num : nums) {
            // 在最少次的紀錄結構內記錄所有數字(一開始每個數字都是0次)
            small.add(new Pair(num, 0));
        }

        for (int i = 0; i < n; i++) {
            // 加入第i個數字
            add(nums[i]);
            // 如果是超過第k的話需要開始移除前面超出範圍的數字
            if (i >= k) {
                remove(nums[i - k]);
            }

            // 第k個之後就需要在加入每個數字之後計算了前x常出現的數字總和了
            if (i >= k - 1) {
                equilibrium(x);
                ans[i - k + 1] = sum;
            }
        }
        return ans;
    }
}

class Pair implements Comparable<Pair> {
    int val;
    int freq;

    public Pair(int v, int f) {
        this.val = v;
        this.freq = f;
    }

    public int compareTo(Pair p) {
        if (this.freq == p.freq) {
            return this.val - p.val;
        } else {
            return this.freq - p.freq;
        }
    }

    public long getTotal() {
        return (long) this.val * this.freq;
    }
}
