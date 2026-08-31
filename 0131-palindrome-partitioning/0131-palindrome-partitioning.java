class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        backtrack(0, s, new ArrayList<>(), ans);
        return ans;
    }

    public void backtrack(int i, String s, List<String> curr, List<List<String>> ans) {

        if (i == s.length()) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int j = i; j < s.length(); j++) {

            if (isPalindrome(i, j, s)) {

                curr.add(s.substring(i, j + 1));
                backtrack(j + 1, s, curr, ans);
                curr.remove(curr.size() - 1);
            }
        }
    }

    public boolean isPalindrome(int left, int right, String s) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}