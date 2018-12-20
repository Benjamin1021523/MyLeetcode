class Solution {
public:
    string originalDigits(string s) {
        int cnt[128] = {0};
        for(auto& i:s)
            ++cnt[i];
        int ans[10] = {0};
        ans[0] = cnt['z'];
        ans[2] = cnt['w'];
        ans[4] = cnt['u'];
        ans[6] = cnt['x'];
        ans[8] = cnt['g'];

        ans[1] = max(cnt['o'] - ans[0] - ans[2] - ans[4], 0);
        ans[3] = max(cnt['t'] - ans[2] - ans[8], 0);
        ans[7] = max(cnt['s'] - ans[6], 0);

        ans[5] = max(cnt['v'] - ans[7], 0);

        ans[9] = max(cnt['i'] - ans[5] - ans[6] - ans[8], 0);

        string re = "";
        for(int i = 0;i < 10;++i)
            re += string(ans[i], '0'+i);
        return re;
    }
};
/**
one     two     three   four    five    six     seven   eight   nine    zero
         w                u               x               g             z
o-2-4-0         t-2-8                           s-6
                                  v-7
                                                                 i-5-6-8
*/