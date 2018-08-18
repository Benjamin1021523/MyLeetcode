func searchInsert(nums []int, target int) int {
    /*for i, j := range nums{
        if j > target || j == target{
            return i
        }
    }
    return len(nums)*/
    
    //換成二分逼近法對golang有顯著提升
    var low, high, mid int
    low = 0; high = len(nums); mid = (low + high) / 2
    for low < high{
        if nums[mid] < target{
            low = mid + 1
        } else{
            high = mid
        }
        mid = (low + high) / 2
    }
    return low
}