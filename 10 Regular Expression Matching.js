var isMatch = function(s, p) {
    var re = new RegExp("^"+p+"$");
    var result = re.exec(s);
    return result != null;
};