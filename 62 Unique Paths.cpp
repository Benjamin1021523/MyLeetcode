class Solution {
public:
    int uniquePaths(int m, int n) {
        target = n + m - 1;
        while(--target){
            Pascal();
        }
        return v_pas[n-1];
    }
private:
    void Pascal(){
        v_pas.insert(v_pas.begin(), 0);
        for(int i = 1;i < v_pas.size();++i){
            v_pas[i-1] += v_pas[i];
        }
    }
    int target;
    vector<int> v_pas = {1};
};