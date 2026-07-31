class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapping;
        int mcount = 0;

        for(int num: nums)
            mapping[num]++;

        for(int num: nums) {
            int count = 0;
            if(!mapping[num - 1]){
                while(mapping[num]) {
                    count++;
                    num++;
                }
                mcount = max(mcount, count);
            }
        }
        return mcount;
    }
};
