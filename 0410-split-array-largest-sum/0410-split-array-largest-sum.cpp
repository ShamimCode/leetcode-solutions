class Solution {
public:
    int countSums(vector<int> arr, int sum) {
		int count = 1;
		int arrSum = 0;
		
		for (int x : arr) {
			if (arrSum + x <= sum)
				arrSum += x;
			else {
				count += 1;
				arrSum = x;
			}
		}
		return count;
	}
	

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
		if (k > n)
			return -1;
		
		int low = *max_element(arr.begin(), arr.end());
		int high = accumulate(arr.begin(), arr.end(), 0);
		
		while (low <= high) {
			int mid = (low + high) / 2;
			int sum = countSums(arr, mid);
			if (sum <= k)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
    }
};