class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;
        vector<vector<string>> ans;
        for(string str: strs) {
           vector<int> cmapping(26, 0);
            for(char ch: str)
                cmapping[ch - 'a']++;

            string key = "";

            for(auto pair: cmapping)
                key+= to_string(pair) + "#";
            mapping[key].push_back(str);                
        }
        for(auto pair: mapping) {
            ans.push_back(pair.second);                
        }
        return ans;
    }
};
