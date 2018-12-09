class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0;i < order.size();++i)
            arr[order[i]] = i;
        for(int i = 1;i < words.size();++i){
            if(!lassthan(words[i-1], words[i])){
                return false;
            }
        }
        return true;
    }
private:
    bool lassthan(string a, string b){
        for(int i = 0;i < a.size() && i < b.size();++i){
            if(arr[a[i]] < arr[b[i]])
                return true;
            if(arr[a[i]] > arr[b[i]])
                return false;
        }
        return a.size() <= b.size();
    }
    int arr[128];
};