//比直接insert到nums快
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> re(nums.end()-k, nums.end());
        re.insert(re.end(), nums.begin(), nums.end()-k);
        nums.assign(re.begin(), re.end());
    }
};