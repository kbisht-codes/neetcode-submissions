class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0, right = 0, result = 0, maxfreq = 0, length = 0;
        while(right < s.size()) {
            count[s[right]]++;
            maxfreq = max(maxfreq, count[s[right]]);
            while(((right - left + 1) - maxfreq) > k) {
                count[s[left]]--;
                left++;
            }
            result = max((right - left + 1), length);
            right++;
        }
        return result;
    }
};
