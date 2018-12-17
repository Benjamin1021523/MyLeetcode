//參考自contest week6，第1名DancingSoul的答案
class Solution {
public:
    int splitArray(vector<int>& nums, int m){
        long long l = 0, r = 0, ans;//nums的最大值、總和(ans的上限、下限)
        for(int i = 0;i < nums.size();++i){
            r += nums[i];
            l = max(l, 1ll * nums[i]);
        }
        long long mid;
        while(l <= r){
            mid = l + r >> 1;//(l + r) >> 1
            if(calc(nums, mid) <= m){//以每組不大於mid的條件，組數是否超過m組?
                ans = mid;//沒超過就記一個可能的答案
                r = mid - 1;//然後mid往下找更小的答案
            }
            else
                l = mid + 1;//超過就mid往上找更大的答案
            //二分逼進法，直到無法二分下去為止
        }
        return ans;
    }
private:
    int calc(const vector<int> &nums, long long lim){
        long long cur = 0;
        int re = 1;//最後一個符合的項在迴圈中算不到
        for (int i = 0;i < nums.size();++i) {
            if(cur + nums[i] <= lim){
                cur += nums[i];
            }
            else{
                cur = nums[i];
                ++re;
            }
        }
        return re;
    }
};