class Solution {
public:
    bool possible(vector<int>& arr, int day, int k, int m) {
		int cnt = 0, ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] <= day) {
				cnt++;
			} else {
				ans += (cnt / k);
				cnt = 0;
			}
		}
		ans += (cnt / k);
		
		return (ans >= m);
	}

    int minDays(vector<int>& arr, int m, int k) {
        long long val = 1LL * m * k;
		if (val > arr.size())
			return - 1;

        int mini = arr[0], maxi = arr[0];
		for (int x : arr) {
			mini = min(mini, x);
            maxi = max(maxi, x);
        }
        		
		int low = mini;
		int high = maxi;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			
			bool pos = possible(arr, mid, k, m);
			
			if (pos)
				high = mid - 1;
			else
				low = mid + 1;
		}
		
		return low;
    }
};