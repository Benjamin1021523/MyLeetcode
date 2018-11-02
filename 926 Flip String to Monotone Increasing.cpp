class Solution {
public:
    int minFlipsMonoIncr(string S) {
        auto start = S.find("1");
        auto end = S.find_last_of("0");
        S = S.substr(start, end - start + 1);
        //把前置0和後置1去除

        int arr[S.size()+1] = {0};
        for(int i = 1;i <= S.size();++i){
            arr[i] = arr[i-1] + (S[i-1] == '1');
        }//記錄累積值

        size_t t, now = 0;
        size_t ans = min(size_t(arr[S.size()]), S.size()-arr[S.size()]);
        //找0和1的數量何者少
        while((t = S.find("01", now)) != string::npos){//找到每個01當斷點
            now = t + 1;
            ans = min(ans, arr[t] + 
                      S.size() - (t+1) - (arr[S.size()] - arr[t]));
            //試試左段的1加上右段的0之數量是否少於目前答案
        }

        return ans;
    }
};