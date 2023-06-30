class Solution {
    public boolean isValid(String s) {
        List<Integer> list = new ArrayList<>();

        boolean ans = true;
        for (char c : s.toCharArray()) {
            if (!ans) break;
            switch (c) {
                case 'a':
                    list.add(1);
                    break;
                case 'b':
                    if (list.isEmpty()) {
                        ans = false;
                    } else if (list.get(list.size() - 1) == 1) {
                        list.set(list.size() - 1, 2);
                    } else {
                        ans = false;
                    }
                    break;
                case 'c':
                    if (list.isEmpty()) {
                        ans = false;
                    } else if (list.get(list.size() - 1) == 2) {
                        list.remove(list.size() - 1);
                    } else {
                        ans = false;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans && list.isEmpty();
    }
}