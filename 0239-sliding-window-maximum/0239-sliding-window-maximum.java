class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];

        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {

            // remove element outside the window
            while (!dq.isEmpty() &&
                    dq.peekFirst() <= i - k) {
                dq.pollFirst();
            }

            // remove smaller/equal elements from back
            while (!dq.isEmpty() &&
                    nums[dq.peekLast()] <= nums[i]) {
                dq.pollLast();
            }

            // Add current index
            dq.offerLast(i);

            // window is ready
            if (i >= k - 1) {
                ans[i - k + 1] = nums[dq.peekFirst()];
            }
        }
        return ans;
    }
}