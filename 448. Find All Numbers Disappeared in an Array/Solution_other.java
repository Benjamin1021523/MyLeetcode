// 改自 https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/1583741/time-o-n-space-o-1/
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int assignIndex = -1;
        for (int i = 0; i < nums.length; i++) {
            assignIndex = Math.abs(nums[i]) - 1;

            // 以儲存的數字標為負值，記錄索引值i+1的數字存在於陣列中
            nums[assignIndex] = Math.abs(nums[assignIndex]) * -1;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                list.add(i + 1);
            };
        }
        
        return list;
    }
}