/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    s = s.trim();

    var re = new RegExp("^[+-]?(([0-9]+)|([0-9]+\\.[0-9]*)|([0-9]*\\.[0-9]+))(e[+-]?[0-9]+)?$");
    var result = re.exec(s);
    console.log(result)
    return result != null;
};