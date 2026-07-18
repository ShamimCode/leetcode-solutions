class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long sum = 0;
        int ans = 1;
        int i = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (1LL * nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};