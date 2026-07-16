class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> words;
        int i = 0;
        while (i < s.size()) {

            while (i < s.size() && s[i] == ' ')
                i++;

            if (i >= s.size())
                break;

            string word = "";
            while (i < s.size() && s[i] != ' ')
                word += s[i++];
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++) {
            ans += words[words.size() - i - 1];
            if (i != words.size() - 1)
                ans += " ";
        }
        return ans;
    }
};