class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        std::unordered_map<char, int> charMap;

        int start = 0;
        int end = 0;
        int maxLen = 0;

        while (end < s.size()) {
            if (start != end) {
                while (charMap[s[end]] && start <= end) {
                    charMap[s[start]]--;
                    start++;
                }
            }

            maxLen = max(maxLen, (end - start) + 1);

            charMap[s[end]]++;
            end++;
        }

        return maxLen;
    }
};
