class Solution {
public:
    bool dayReq(vector<int> arr, int cap, int days) {
        int day = 1, load = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (load + arr[i] > cap) {
                day++;
                load = arr[i];
                if (day > days) return false;
            } else {
                load += arr[i];
            }
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;

            int pos = dayReq(arr, mid, days);

            if (pos)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};