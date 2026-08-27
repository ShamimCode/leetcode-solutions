class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombination(0, candidates, target, new ArrayList<>(), ans);
        return ans;
    }

    void findCombination(int i, int[] arr, int target, List<Integer> curr, List<List<Integer>> ans) {

        if (i == arr.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(curr));
            }
            return;
        }

        if (arr[i] <= target) {
            curr.add(arr[i]);
            findCombination(i, arr, target - arr[i], curr, ans);
            curr.remove(curr.size() - 1);
        }
        findCombination(i+1, arr, target, curr, ans);
    }
}