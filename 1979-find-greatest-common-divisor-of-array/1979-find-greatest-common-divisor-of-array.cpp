class Solution {
public:

    int _gcd(int a, int b) {
        if (b == 0) return a;
        return _gcd(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int maxi = nums[0], mn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            mn = min(mn, nums[i]);
        }
        return _gcd(maxi, mn);
    }
};