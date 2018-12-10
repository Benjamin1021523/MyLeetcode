class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string temp;
        //深度和長度
        vector<pair<int, int>> v({make_pair(-1, 0)});
        //是否是檔案
        vector<bool> file({false});
        while(getline(ss, temp)){
            int t = temp.find_first_not_of("\t");
            v.push_back(make_pair(t, temp.size()-t));
            file.push_back(temp.find(".") != string::npos);
        }
        int out = 0;
        for(int i = 1, j;i < v.size();++i){
            j = i-1;
            while(v[i].first <= v[j].first) --j;//往上找
            v[i].second += v[j].second;//往下累積
            if(file[i])//只取是檔案的路徑
                out = max(out, v[i].first + v[i].second);
        }
        return out;
    }
};
/**
class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string temp;
        vector<string> v;
        while(getline(ss, temp)){
            v.push_back(temp);
        }
        int out = 0;
        vector<int> nums({0});
        for(int i = 0;i < v.size();++i){
            int cnt = v[i].find_first_not_of("\t");
            if(cnt+2 == nums.size())
                nums[nums.size()-1] = nums[nums.size()-2] + v[i].size()-cnt;
            else if(cnt+2 > nums.size())
                nums.push_back(nums[nums.size()-1] + v[i].size()-cnt);
            else{
                nums.resize(cnt+2);
                nums[nums.size()-1] = nums[nums.size()-2] + v[i].size()-cnt;
            }
            //for(auto j:nums){
            //    cout << j << " ";
            //}cout << endl;
            if(v[i].find(".") != string::npos)
                out = max(out, int(nums[nums.size()-1] + nums.size()-2));
        }
        return out;
    }
};*/