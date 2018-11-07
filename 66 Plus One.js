/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    digits.splice(0,0,0);
    digits[digits.length-1]++;
    for(var i = digits.length-1;i > 0;i--){
        if(digits[i] == 10){
            digits[i-1]++;
            digits[i] = 0;
        }
        else{
            return digits.slice(1, digits.length);
        }
    }
    return digits;

    //overflow
    //return (parseInt(digits.join(''))+1).toString().split('');
};