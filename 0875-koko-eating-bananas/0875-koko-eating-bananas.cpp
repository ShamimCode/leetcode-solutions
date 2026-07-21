class Solution {
public:
    long long calcTimeTaken(vector<int> nums, int hourly) {
        long long timeTaken = 0;
        for (int num : nums) {
            timeTaken += ceil((double)num/(double)hourly);
        }
        return timeTaken;
    }
    
    int findMax(vector<int> nums) {
        int maxi = -1;
        for (int num: nums) maxi = max(num, maxi);
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        
        while (low <= high) {
            int mid = (low + high) / 2;
            long long timeTaken = calcTimeTaken(piles, mid);
            
            if (timeTaken <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};