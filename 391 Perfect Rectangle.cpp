class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;
        pair<int, int> ld(rectangles[0][0], rectangles[0][1]);//左下角的點
        pair<int, int> ru(rectangles[0][2], rectangles[0][3]);//右上角的點
        int face = 0;//記錄面積
        for(auto& i:rectangles){
            ld.first = min(ld.first, i[0]);
            ld.second = min(ld.second, i[1]);
            ru.first = max(ru.first, i[2]);
            ru.second = max(ru.second, i[3]);
            
            //標記每個矩形的四角
            ++m[make_pair(i[0], i[1])];
            ++m[make_pair(i[0], i[3])];
            ++m[make_pair(i[2], i[1])];
            ++m[make_pair(i[2], i[3])];
            face += (i[2] - i[0]) * (i[3] - i[1]);
            if(face > (ru.first - ld.first) * (ru.second - ld.second))//表示有重疊部分
                return false;
        }
        if(face != (ru.first - ld.first) * (ru.second - ld.second) || //理想面積和實際面積不同時
           m[ld] != 1 || m[ru] != 1 || 
           m[make_pair(ld.first, ru.second)] != 1 || 
           m[make_pair(ru.first, ld.second)] != 1)
            return false;

        int cnt = 0;
        for(auto& i:m){//理論上只有最外面的四角是1，裡面都該是2才對
            if(i.second % 2){
                ++cnt;
            }
        }
        return cnt == 4;
    }
};