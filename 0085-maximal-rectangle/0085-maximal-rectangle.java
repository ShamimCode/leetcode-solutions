class Solution {

    public static int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int maxArea = 0;

        for (int i = 0; i <= heights.length; i++) {
            int currHeight = (i == heights.length) ? 0 : heights[i];

            while (!st.isEmpty() &&
                    heights[st.peek()] > currHeight
            ) {
                int height = heights[st.pop()];
                int width = (st.isEmpty()) ? i : i - st.peek() - 1;

                int area = height * width;
                maxArea = Math.max(area, maxArea);
            }

            if (i < heights.length) {
                st.push(i);
            }
        }
        return maxArea;
    }

    public int maximalRectangle(char[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[] height = new int[m];
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            int area = largestRectangleArea(height);
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }
}