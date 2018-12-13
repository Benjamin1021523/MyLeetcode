class Solution {
public:
    int maxRotateFunction(vector<int> A) {
        int first = 0, total = 0, siz = A.size();
        for(int i = 0;i < siz;++i){
            first += i * A[i];
            total += A[i];
        }
        int ma = first;
        for(int i = 0;i < siz - 1;++i){
            first -= (total - siz * A[i]);
            ma = max(ma, first);
        }
        return ma;
    }
};