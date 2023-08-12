class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        boolean[] existNumber = new boolean[nums.length];

        for (int num : nums) {
            existNumber[num - 1] = true;
        }

        List<Integer> ans = new ArrayList<>();
        for (int index = 0;index < existNumber.length; index++) {
            if (!existNumber[index]) {
                ans.add(index + 1);
            }
        }

        return ans;
    }
}