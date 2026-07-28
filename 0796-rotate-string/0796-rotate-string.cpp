class Solution {
public:
    bool rotateString(string s, string t) {
        if (s.size() != t.size()) return false;

        string str = s + s;
        return str.find(t) != string::npos;
    }
};