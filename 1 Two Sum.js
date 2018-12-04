/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var dict = {};
    for(var i = 0;i < nums.length;++i){
        if(dict[nums[i]] != undefined && target == nums[i] * 2)
            return [dict[nums[i]], i];
        dict[nums[i]] = i;
    }
    for(var i = 0;i < nums.length;++i){
        //用nums的順序處理可以確保回傳值由小到大
        if(typeof dict[target - nums[i]] != 'undefined' && nums[i]*2 != target)
            return [i, dict[target - nums[i]]]
    }
    /*//對字典處理的寫法
    for(var i in dict){
        if(dict[target - i] != undefined)
            return [dict[i], dict[target - i]]
    }*/
};
//dict[nums[i]] != undefined
//typeof dict[target - nums[i]] != 'undefined'
//這兩個效果一樣