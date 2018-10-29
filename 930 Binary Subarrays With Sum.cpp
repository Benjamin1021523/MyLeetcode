class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int cnt = 0;
        A.insert(A.begin(), 0);
        for(int i = 1;i < A.size();++i){
            A[i] += A[i-1];
        }
        for(int i = 0;i < A.size();++i){
            int j = A.size()-1;
            while(i < j && A[j] - A[i] >= S){
                if(A[j] - A[i] == S){
                    ++cnt;
                }
                --j;
            }
        }
        /*for(auto i:A){
            cout << i << " ";
        }*/
        return cnt;
    }
};