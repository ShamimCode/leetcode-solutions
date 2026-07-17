class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (arr[mid] == key) return mid;
            
            // left sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= key && key <= arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } 
            // right sorted
            else {
                if (arr[mid] <= key && key <= arr[high])
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
        }
        return -1;
    }
};