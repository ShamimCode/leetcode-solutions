class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxi = candies[0];
        for (int i = 1; i < n; i++)
            maxi = max(maxi, candies[i]);

        vector<bool> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = ((candies[i] + extraCandies) >= maxi) ? true : false;
        }
        return result;
    }
};