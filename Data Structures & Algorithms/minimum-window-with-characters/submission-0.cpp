class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countS, countT;
        for(char c : t)
            countT[c]++;
        pair<int, int> ipair = {-1, -1};
        int need = countT.size(), have = 0, left = 0, minlen = INT_MAX;

        for(int right = 0; right < s.size(); right++) {
            char ch = s[right];
            countS[ch]++;
            if(countT.count(ch) && countT[ch] == countS[ch])
                have++;
            while(have == need) {
                if((right - left + 1) < minlen) {
                    minlen = right - left + 1;
                    ipair = {left, right};
                }
                countS[s[left]]--;
                if(countT.count(s[left]) && countT[s[left]] > countS[s[left]])
                    have--;
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(ipair.first, minlen);
    }
};
