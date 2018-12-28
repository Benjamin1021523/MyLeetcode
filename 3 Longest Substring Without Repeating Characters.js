/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s.length < 2)
        return s.length;
    var arr = new Array(130);
    for(var i = 0;i < 130;++i)
        arr[i] = 0;
    var cnt = 0;
    for(var i = 0;i < s.length && s.length - i > cnt;++i){
        for(j = i;j < s.length && arr[s[j].charCodeAt()] == 0;++j){
            arr[s[j].charCodeAt()] = 1;
        }
        if(j - i > cnt)
            cnt = j - i;
        for(var k = i;k < j;++k)
            arr[s[k].charCodeAt()] = 0;
    }
    return cnt;
};
//char to int: .charCodeAt()