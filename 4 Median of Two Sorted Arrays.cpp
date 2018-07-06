class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge(nums1.size() + nums2.size(), 0);
        for(int i = 0, j = 0;i < nums1.size() || j < nums2.size();){
            if(i == nums1.size()){//nums1用完時
                merge[i + j] = nums2[j++];
            }
            else if(j == nums2.size()){//nums2用完時
                merge[i + j] = nums1[i++];
            }
            else{//兩個都沒用完
                if(nums1[i] < nums2[j]){
                    merge[i + j] = nums1[i++];
                }
                else{
                    merge[i + j] = nums2[j++];
                }
            }
        }

        if(merge.size() % 2){
            return 1.0 * merge[merge.size() / 2];
        }
        else{
            return 0.5 * (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]);
        }
    }
};