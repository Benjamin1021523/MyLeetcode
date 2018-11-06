/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {//效率不高但是好看
    var re = new RegExp("([A-Za-z]+) *$");
    var result = re.exec(s);
    if(result == null)
        return 0;
    return result[1].length;
};