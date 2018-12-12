//最後一個']'的搭配不知道在哪，但是最右邊的'['的搭配一定是往右第一個']'
class Solution {
public:
    string decodeString(string s) {
        int last;
        while((last = s.find_last_of("[")) != string::npos){
            int st = s.find_last_not_of("0123456789", last - 1) + 1;
            int en = s.find("]", last) + 1;

            s.replace(st, en - st, f(s.substr(st, en - st), last - st));
        }
        return s;
    }
private:
    string f(string a, int asc91){
        cout << a << endl;
        int num = atoi(a.substr(0, asc91).c_str());
        string s = "";
        for(int i = asc91+1;a[i] != ']';++i)
            s += a[i];
        string re;
        for(int i = 0;i < num;++i)
            re += s;
        return re;
    }
};