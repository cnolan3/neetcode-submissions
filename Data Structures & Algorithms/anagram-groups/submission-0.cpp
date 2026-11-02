class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return vector<vector<string>>{strs};

        std::unordered_map<string, vector<string>> groups;
        int charCount[26] = {0};

        for (int i = 0; i < strs.size(); i++) {
            std::fill(std::begin(charCount), std::end(charCount), 0);
            string key = "";

            for (int e = 0; e < strs[i].size(); e++) {
                charCount[strs[i][e] - 'a']++;
            }

            for (int e = 0; e < 26; e++) {
                key += "#";
                key += (char)('0' + charCount[e]);
            }

            if (groups.contains(key)) {
                groups[key].push_back(strs[i]);
            } else {
                groups[key] = vector<string>{strs[i]};
            }
        }

        vector<vector<string>> ret;

        for (const auto& [key, group] : groups) {
            ret.push_back(group);
        }

        return ret;
    }
};
