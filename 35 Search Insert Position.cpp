//追過第二名的人還是第二名
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*int now = nums.size() / 2;
        for(int i = 0;i < nums.size();++i){
            if(target == nums[i] || target < nums[i])
                return i;
        }
        return nums.size();*/
		
		//改成二分逼近法，雖然效能沒差很多
        int low = 0, high = nums.size(), mid = (low + high) / 2;
        while(low < high){
            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
            mid = (low + high) / 2;
        }
        return low;
    }
};