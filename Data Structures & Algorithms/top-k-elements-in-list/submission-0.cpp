class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<vector<int>> freq(nums.size() + 1);
        for(int num: nums)
            counts[num]++;

        for(auto count: counts)
            freq[count.second].push_back(count.first);
        
        vector<int> ans;
        for(int i = freq.size() - 1; i > 0; i--){
            for(int entry: freq[i]) {
                ans.push_back(entry);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
