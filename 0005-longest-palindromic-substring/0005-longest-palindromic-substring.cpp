class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
		int n = s.size(), resLen = 0;
		
		for (int i = 0; i < n; i++) {
			// odd len
			int l = i, r = i;
			while (l >= 0 && r < n && s[l] == s[r]) {
				if (r - l + 1 > resLen) {
					resLen = r - l + 1;
					res = s.substr(l, r - l + 1);
				}
				l -= 1;
				r += 1;
			}
			
			// even len
			l = i, r = i + 1;
			while (l >= 0 && r < n && s[l] == s[r]) {
				if (r - l + 1 > resLen) {
					resLen = r - l + 1;
					res = s.substr(l, r - l + 1);
				}
				l -= 1;
				r += 1;
			}
		}
		return res;
    }
};