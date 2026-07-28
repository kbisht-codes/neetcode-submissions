class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hsh(nums.size());

        for(auto& num: nums)
            hsh[num]+= 1;
        
        int start, count = 0, ans = 0;
        for(int num: nums) {
            if(!hsh[num - 1]){
                count = 0;
                while(hsh[num]){
                    count++;
                    num++;
                }
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
