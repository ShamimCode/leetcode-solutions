class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n*m - 1;

        while (low <= high) {
            int mid = (low + high) >> 1;
            int elm = mat[mid / m][mid % m];

            if (elm == k) return true;
            else if (elm < k) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};