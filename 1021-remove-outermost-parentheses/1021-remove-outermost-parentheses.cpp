class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
		string res = "";
		
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				cnt++;
				if (cnt > 1)
					res += s[i];
			} else {
				cnt--;
				if (cnt > 0)
					res += s[i];
			}
		}
		return res;
    }
};