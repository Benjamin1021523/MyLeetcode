//1的延伸題
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                //if(numbers[l] == numbers[r])  //有沒有這個都能過
                //    return {l+1, l+2};
                return {l+1, r+1};
            }
            else if(numbers[l] + numbers[r] > target)
                --r;
            else
                ++l;
        }
    }
};