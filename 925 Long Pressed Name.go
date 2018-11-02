func isLongPressedName(name string, typed string) bool {
    r := 0
    for i := 0;i < len(typed) && r != len(name);i++{
        if typed[i] == name[r]{
            r++
        }
    }
    return r == len(name)
}