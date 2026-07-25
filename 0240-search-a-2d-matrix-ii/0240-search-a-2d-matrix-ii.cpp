class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        if (n == 1 && m == 1) return mat[0][0] == k;

        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            int elm = mat[row][col];

            if (elm == k)
                return true;
            else if (elm < k)
                row++;
            else if (elm > k)
                col--;
        }
        return false;
    }
};