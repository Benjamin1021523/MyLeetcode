/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var arr = path.split("/");
    for(var i = 0;i < arr.length;++i){
        if(arr[i] == "" || arr[i] == "."){
            arr.splice(i, 1);
		    --i;
        }
    }
    var re = []
    for(var i = 0;i < arr.length;++i){
        if(arr[i] == "..")
            re.length = (re.length == 0 ? 0 : re.length-1);
        else
            re[re.length] = arr[i];
    }
    if(re.length == 0)
        return "/";
    return '/' + re.join('/');
};