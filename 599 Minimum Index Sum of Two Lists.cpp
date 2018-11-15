class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> re;
        int plus = 0;
        while(plus != list1.size() + list2.size() - 1){
            for(int i = 0;i <= plus;++i){
                if(plus-i >= list2.size())
                    continue;
                if(i == list1.size())
                    break;
                if(list1[i] == list2[plus-i])
                    re.push_back(list1[i]);
            }
            if(!re.empty())
                return re;
            ++plus;
        }
        return re;
    }
};
/*
  1 2
3 x x
4 x x
5 x x
2 x y
*/