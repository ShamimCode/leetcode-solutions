class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] res = new int[n];
        Arrays.fill(res, -1);

        for (int i = 2*n-1; i>= 0; i--) {
            int idx = i % n;
            while (!st.isEmpty() && st.peek() <= nums[idx]) {
                st.pop();
            }

            if (i < n && !st.isEmpty()) {
                res[i] = st.peek();
            }

            st.push(nums[idx]);
        }

        return res;
    }
}