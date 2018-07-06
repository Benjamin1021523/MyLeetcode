/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var regex = /^ *([+-]?0*[0-9]+)/;
    var num_arr = regex.exec(str);

    if(num_arr == null)//不是數字的情況
        return 0;

    var num_js = parseInt(num_arr[1]);
    if(num_js > 2147483647){
        return 2147483647;
    }
    else if(num_js < -2147483648){
        return -2147483648;
    }
    else{
        return num_js;
    }
};