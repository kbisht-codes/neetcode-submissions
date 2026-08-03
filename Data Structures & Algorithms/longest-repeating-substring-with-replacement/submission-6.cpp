class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, max_freq = 0, l = 0, r = 0;
        unordered_map<char, int> count;
        while(r < s.size()) {
            count[s[r]]++;
            max_freq = max(max_freq, count[s[r]]);
            while((r - l + 1) - max_freq > k) {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, (r - l + 1));
            r++;
        }
        return ans;
    }
};
