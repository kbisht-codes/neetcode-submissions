class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> countS;
        for(char c: t)
            countT[c]++;

        int l = 0, r = 0, need = countT.size(), having = 0, mlen = INT_MAX;
        pair<int, int> ipair = {-1, -1};
        while(r < s.size()) {
            countS[s[r]]++;
            if(countT.count(s[r]) && countT[s[r]] == countS[s[r]]) {
                having++;
            }
            while(having == need) {
                if((r - l + 1) < mlen) {
                    mlen = r - l + 1;
                    ipair = {l, r};
                }
                countS[s[l]]--;
                if(countT.count(s[l]) && countS[s[l]] < countT[s[l]])
                    having--;
                l++;
            }
            r++;
        }
        return mlen != INT_MAX ? s.substr(ipair.first, mlen) : "";
    }
};
