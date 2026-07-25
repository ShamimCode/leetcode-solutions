class Solution {
public:
    int findMaxRow(vector<vector<int>> arr, int n, int m, int col) {
        int max_val = -1e6;
        int i = -1;

        for (int row = 0; row < n; row++) {
            if (arr[row][col] > max_val) {
                max_val = arr[row][col];
                i = row;
            }
        }
        return i;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = findMaxRow(mat, n, m, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;
            int elm = mat[row][mid];

            if (elm > left && elm > right)
                return {row, mid};
            else if (elm < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};