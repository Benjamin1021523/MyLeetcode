class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k > int(s.size())-2)
            return s.size();
        vector<pair<char, int>> v({make_pair(s[0], 1)});
        for(int i = 1;i < s.size();++i){
            if(s[i] == s[i-1])
                ++v[v.size()-1].second;
            else
                v.push_back(make_pair(s[i], 1));
        }
        int re = 0, l, r, cnt, op;
        for(int i = 0;i < v.size();++i){
            l = i-1, r = i+1, cnt = v[i].second, op = k;
            while(r != v.size() && op > 0 || (op == 0 && v[r].first == v[i].first)){
                if(v[r].first == v[i].first)
                    cnt += v[r].second;
                else{
                    cnt += min(v[r].second, op);
                    op -= v[r].second;
                }
                if(op < 0)  break;
                ++r;
            }
            while(l >= 0 && op > 0 || (op == 0 && v[l].first == v[i].first)){
                if(v[l].first == v[i].first)
                    cnt += v[l].second;
                else{
                    cnt += min(v[l].second, op);
                    op -= v[l].second;
                }
                if(op < 0)  break;
                --l;
            }
            if(cnt > re)
                re = cnt;
        }
        return re;
    }
};