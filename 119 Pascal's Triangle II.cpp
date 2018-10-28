class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out(1,1);
        int temp;
        for(int i = 0;i < rowIndex;++i){
            vector<int> temp(out);
            for(int j = 1;j < out.size();++j){
                out[j] += temp[j-1];
            }
            out.push_back(1);
        }
        return out;
    }
};