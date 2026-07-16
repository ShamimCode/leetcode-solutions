class Solution {
public:
    string vowels = "aAeEiIoOuU";
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {

            while (i < j && vowels.find(s[i]) == string::npos)
                i++;
            while (i < j && vowels.find(s[j]) == string::npos)
                j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};