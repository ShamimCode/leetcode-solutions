class Solution {

    public long subArrayRanges(int[] nums) {
        return sumMax(nums) - sumMin(nums);
    }

    public static long sumMax(int[] arr) {
        int n = arr.length;
        long total = 0;

        int[] pgee = findPGEE(arr, n);
        int[] nge = findNGE(arr, n);

        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            long contribution = (long) arr[i] * left * right;
            total += contribution;
        }

        return total;
    }

    public static long sumMin(int[] arr) {
        int n = arr.length;
        long total = 0;

        int[] psee = findPSEE(arr, n);
        int[] nse = findNSE(arr, n);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            long contribution = (long) arr[i] * left * right;
            total += contribution;
        }

        return total;
    }

    // Previous Smaller or Equal
    public static int[] findPSEE(int[] arr, int n) {
        int[] psee = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {

            while (!st.isEmpty() && arr[st.peek()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.isEmpty() ? -1 : st.peek();

            st.push(i);
        }

        return psee;
    }

    // Next Smaller
    public static int[] findNSE(int[] arr, int n) {
        int[] nse = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.isEmpty() && arr[st.peek()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.isEmpty() ? n : st.peek();

            st.push(i);
        }

        return nse;
    }

    // Previous Greater or Equal
    public static int[] findPGEE(int[] arr, int n) {
        int[] pgee = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {

            while (!st.isEmpty() && arr[st.peek()] < arr[i]) {
                st.pop();
            }

            pgee[i] = st.isEmpty() ? -1 : st.peek();

            st.push(i);
        }

        return pgee;
    }

    // Next Greater
    public static int[] findNGE(int[] arr, int n) {
        int[] nge = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.isEmpty() && arr[st.peek()] <= arr[i]) {
                st.pop();
            }

            nge[i] = st.isEmpty() ? n : st.peek();

            st.push(i);
        }

        return nge;
    }
}