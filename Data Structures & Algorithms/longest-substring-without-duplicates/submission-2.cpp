class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str = "";
        int ans = 0;
        for(auto c: s) {
            while(find(str.begin(), str.end(), c) != str.end()) {
                ans = max(ans, int(str.size()));
                str = str.substr(1);
            }
            str+= c;
        }
        ans = max(ans, int(str.size()));
        return ans;
    }
};
