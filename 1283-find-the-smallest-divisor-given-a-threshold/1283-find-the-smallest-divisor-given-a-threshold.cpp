class Solution {
public:
    bool possible(vector<int> nums, int mid, int threshold) {
        long long ans = 0;
        for (int num : nums) {
            ans += (num + mid - 1) / mid;
            if (ans > threshold)
                return false;
        }
        return ans <= threshold;
    }

    int findMax(vector<int> arr) {
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++)
            maxi = max(maxi, arr[i]);
        return maxi;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(nums, mid, threshold))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};