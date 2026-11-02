class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int charCount[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            charCount[s.c_str()[i] - 'a']++;
            charCount[t.c_str()[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (charCount[i] != 0) return false;
        }

        return true;
    }
};
