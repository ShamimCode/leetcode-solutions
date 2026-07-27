class Solution {
public:
    string largestOddNumber(string s) {
        int i;
        int idx = -1;
        for (i = s.size(); i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                idx = i;
                break;
            }
        }

        i = 0;
        for (i = 0; i < s.size() && i <= idx && s[i] == '0'; i++) { }

        return s.substr(i, idx - i + 1);
    }
};