class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> counts(nums.size() + 1);
        
        for(int num: nums)
            freq[num]++;

        for(auto pair: freq)
            counts[pair.second].push_back(pair.first);
        
        vector<int> ans;
        for(int i = counts.size() - 1; i >= 0; i--) {
            for(int value: counts[i]) {
                ans.push_back(value);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
