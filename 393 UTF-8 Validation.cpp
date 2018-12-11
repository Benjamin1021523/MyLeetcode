class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.empty())
            return true;

        if(data[0] > 255)
            return false;
        int n = 0;
        switch(data[0] & 248){//11111xxx
            case 240://11110xxx
                n = 3;
                break;
            case 224://11100xxx
            case 232://11101xxx
                n = 2;
                break;
            case 192://11000xxx
            case 200://11001xxx
            case 208://11010xxx
            case 216://11011xxx
                n = 1;
                break;
        }
        if(!n && (data[0] & 128))
            return false;
        for(int i = 1;i <= n;++i){
            if(i == data.size() || data[i] > 255 || (data[i] & 192) != 128)
                return false;
        }
        data.erase(data.begin(), data.begin()+n+1);

        return validUtf8(data);
    }
};