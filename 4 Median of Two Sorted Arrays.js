/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var target = (nums1.length + nums2.length) / 2;
    var j = 0;
    var k = 0;
    var re = 1.0;
    while(j + k < target){
        if(j == nums1.length){
            re = nums2[k++];
        }
        else if(k == nums2.length){
            re = nums1[j++]
        }
        else{
            if(nums1[j] < nums2[k]){
                re = nums1[j++];
            }
            else{
                re = nums2[k++];
            }
        }
    }
    if((nums1.length + nums2.length) % 2)
        return re;
    else{
        if(j == nums1.length)
            return (re + nums2[k]) / 2.0
        else if(k == nums2.length)
            return (re + nums1[j]) / 2.0
        else{
            if(nums1[j] < nums2[k])
                return (re + nums1[j]) / 2.0
            else
                return (re + nums2[k]) / 2.0
        }
    }
};
//別往去頭去尾的方向想，只是要找中位數就不用改動原資料了，效率超差