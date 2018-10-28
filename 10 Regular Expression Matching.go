func isMatch(s string, p string) bool {
    matched, _ := regexp.MatchString("^" + p + "$", s)
	//fmt.Println(matched, err)
    return matched
}