package com.easy.find_x_sum_of_all_k_long_subarrays_i_3318;

import java.util.*;

public class Solution extends AbstractSolution {
    public int[] findXSum(int[] nums, int k, int x) {
        XSumData xSumData = new XSumData();

        for (int i = 0; i < k; i++) {
            xSumData.add(nums[i]);
        }

        System.out.println("xSumData.dataMap = " + xSumData.dataMap);
        System.out.println("xSumData.nowCountMap " + xSumData.nowCountMap);

        int[] output = new int[nums.length - k + 1];
        output[0] = xSumData.getSum(x);

        for (int i = k; i < nums.length; i++) {
            if (nums[i] != nums[i - k]) {
                xSumData.add(nums[i]);
                xSumData.remove(nums[i - k]);
            }
            output[i - k + 1] = xSumData.getSum(x);


            System.out.println("xSumData.dataMap = " + xSumData.dataMap);
            System.out.println("xSumData.nowCountMap " + xSumData.nowCountMap);
        }

        return output;
    }

    private static class XSumData {
        private final SortedMap<Integer, SortedSet<Integer>> dataMap = new TreeMap<>(Comparator.reverseOrder());
        private final Map<Integer, Integer> nowCountMap = new HashMap<>();

        public void add(int num) {
            int nowCount = nowCountMap.merge(num, 1, Integer::sum);

            if (nowCount == 1) {
                SortedSet<Integer> count1Set = dataMap.computeIfAbsent(1, k -> new TreeSet<>(Comparator.reverseOrder()));

                count1Set.add(num);
            } else {
                dataMap.get(nowCount - 1).remove(num);

                SortedSet<Integer> countNSet = dataMap.computeIfAbsent(nowCount, k -> new TreeSet<>(Comparator.reverseOrder()));
                countNSet.add(num);
            }
        }

        public void remove(int num) {
            int nowCount = nowCountMap.merge(num, -1, Integer::sum);

            dataMap.get(nowCount + 1).remove(num);

            if (nowCount != 0) {
                SortedSet<Integer> countNSet = dataMap.get(nowCount);
                countNSet.add(num);
            }
        }

        public int getSum(int x) {
            int sum = 0;
            int count = 0;

            for (SortedMap.Entry<Integer, SortedSet<Integer>> entry : dataMap.entrySet()) {
                SortedSet<Integer> sortedSet = entry.getValue();
                for (int num : sortedSet) {
                    sum += num * entry.getKey();
                    count++;

                    if (count == x) {
                        break;
                    }
                }
                if (count == x) {
                    break;
                }
            }
            return sum;
        }
    }
}
