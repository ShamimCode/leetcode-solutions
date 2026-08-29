class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        backtrack(0, nums, ds, ans);
        return ans;
    }

    public static void backtrack(
        int start,
        int[] arr,
        List<Integer> ds,
        List<List<Integer>> ans
    ) {

        ans.add(new ArrayList<>(ds));

        for (int i = start; i < arr.length; i++) {

            // skip duplicates
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }

            ds.add(arr[i]);

            backtrack(i + 1, arr, ds, ans);

            ds.remove(ds.size() - 1);
        }
    }
}