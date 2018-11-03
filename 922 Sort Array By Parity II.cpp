class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddi = A.size() - 1, eveni = A.size() - 2;
        for(int i = 0;i < A.size();++i){
            if(!(i % 2 ^ A[i] % 2)){
                continue;
            }

            while(A[eveni] % 2 == 0 && eveni > 0){
                eveni -= 2;
            }
            while(A[oddi] % 2 == 1 && oddi > 1){
                oddi -= 2;
            }
            if(i % 2){
                swap(A[i], A[eveni]);
                eveni -= 2;
            }
            else{
                swap(A[i], A[oddi]);
                oddi -= 2;
            }
        }
        return A;
    }
};