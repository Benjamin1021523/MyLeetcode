class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int leng = numRows;
        while((leng += 2 * numRows - 2) < s.size()){}
        s += string(leng - s.size(), ' ');

        string re(1, s[0]);
        vector<int> data;
        for(int i = 2 * numRows - 2;i < s.size();i += 2 * numRows - 2){
            data.push_back(i);
            re += s[i];
        }//最上一排
        for(int i = 1;i < numRows - 1;++i){
            re += s[i];
            for(int j = 0;j < data.size();++j){
                re += s[data[j]-i];
                re += s[data[j]+i];
            }
        }//中段
        for(int i = numRows-1;i < s.size();i += 2 * numRows - 2){
            re += s[i];
        }//最下一排
        while(re.find(" ") != string::npos){
            re.erase(re.find(" "), 1);
        }
        return re;
    }
};