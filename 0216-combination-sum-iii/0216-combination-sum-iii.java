class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), ans);

        return ans;
    }

    public static void backtrack(int idx, int t, int k, List<Integer> curr, List<List<Integer>> ans) {

        if (k == 0 && t == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int i = idx; i <= 9; i++) {
            curr.add(i);

            backtrack(i + 1, t - i, k - 1, curr, ans);
            curr.remove(curr.size() - 1);
        }
    }
}