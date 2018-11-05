class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        data.clear();
        for(int i = 0;i < matrix.size();++i)
            data.push_back(matrix[i]);
        re.assign(data[0].begin(), data[0].end());
        data.erase(data.begin());

        if(!data.empty())
            b();
        return re;
    }
private:
    vector<vector<int>> data;//把輸入變成class內區域變數
    vector<int> re;//用於回傳的陣列
    void a(){//上
        for(int i = 0;i < data[0].size();++i){
            re.push_back(data[0][i]);
        }
        data.erase(data.begin());
        if(!data.empty())
            b();
    }
    void b(){//右
        for(int i = 0;i < data.size();++i){
            re.push_back(data[i][data[i].size()-1]);
            data[i].erase(data[i].end()-1);
        }
        if(!data[data.size()-1].empty())
            c();
    }
    void c(){//下
        for(int i = data[data.size()-1].size() - 1;i >= 0;--i){
            re.push_back(data[data.size()-1][i]);
        }
        data.erase(data.end()-1);
        if(!data.empty())
            d();
    }
    void d(){//左
        for(int i = data.size()-1;i >= 0;--i){
            re.push_back(data[i][0]);
            data[i].erase(data[i].begin());
        }
        if(!data[0].empty())
            a();
    }
};