class Solution {
    private final String[] letters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        backtrack(0, digits, new StringBuilder(), ans);
        return ans;
    }

    private void backtrack(int i, String digits, StringBuilder curr, List<String> ans) {

        if (i == digits.length()) {
            ans.add(curr.toString());
            return;
        }

        String possibleLetters = letters[digits.charAt(i) - '0'];
        for (char c : possibleLetters.toCharArray()) {
            curr.append(c);

            backtrack(i + 1, digits, curr, ans);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
}