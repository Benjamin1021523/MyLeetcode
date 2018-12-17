//改寫自contest week8，第2名mgch的答案，非常漂亮的方法
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //這個方法用bitset記錄可以由nums組成的數字
        //nums長度不超過200，元素不超過100，總和不超過20000，所以一半等於10000
        bitset<10001> bit;
        bit[0] = true;
        int sum = 0;
        for(int i = 0;i < nums.size();++i){
            bit |= bit << nums[i];//nums[i]之前的數字全部加上nums[i]，然後把nums[i]也放進去
            sum += nums[i];
        }
        if(sum % 2 == 0 && bit[sum / 2] == 1)
            return true;
        return false;
    }
};
/**
//把同樣的邏輯用set寫了一次，然後timeout
set<int> s;
s.insert(0);
int sum = 0;
for(auto& i:nums){
    set<int> st(s);
    for(auto& j:st)
        s.insert(i + j);
    sum += i;
}
if(sum % 2 == 0 && s.find(sum / 2) != s.end())
    return true;
return false;*/