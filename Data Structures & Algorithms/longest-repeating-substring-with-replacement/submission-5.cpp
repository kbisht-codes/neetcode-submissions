class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int mfreq = 0, l = 0, r = 0, ans = 0;
        while(r < s.size()) {
            count[s[r]]++;
            mfreq = max(mfreq, count[s[r]]);
            while((r - l + 1) - mfreq > k) {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, (r - l + 1));
            r++;
        }
        return ans;
    }
};
