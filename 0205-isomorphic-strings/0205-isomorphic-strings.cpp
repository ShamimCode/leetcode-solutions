class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            if (m1.find(c1) == m1.end() && m2.find(c2) == m2.end()) {
                m1[c1] = c2;
                m2[c2] = c1;
            } else {
                if (m1[c1] != c2 || m2[c2] != c1)
                    return false;
            }
        }
        return true;
    }
};