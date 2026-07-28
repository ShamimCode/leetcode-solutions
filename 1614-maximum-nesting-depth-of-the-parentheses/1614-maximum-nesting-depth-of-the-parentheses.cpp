class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCount = -1;
        for (char ch : s) {
            if (ch == '(') cnt++;
            if (ch == ')') cnt--;
            maxCount = max(maxCount, cnt); 
        }
        return maxCount;
    }
};