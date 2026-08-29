class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        findCombination(0, candidates, target, new ArrayList<>(), ans);
        return ans;
    }

    public void findCombination(int idx, int[] arr, int target, List<Integer> ds, List<List<Integer>> ans) {
        
        if (target == 0) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            if (i > idx && arr[i] == arr[i-1]) continue;
            if (arr[i] > target) break;

            ds.add(arr[i]);
            findCombination(i + 1, arr, target - arr[i], ds, ans);
            ds.remove(ds.size() - 1);
        }
    }
}