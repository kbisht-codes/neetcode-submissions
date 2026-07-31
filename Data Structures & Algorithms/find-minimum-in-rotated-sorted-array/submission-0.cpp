class Solution {
public:
    int findMin(vector<int> &nums) {
        int  res = INT_MAX, l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            res = min(res, nums[m]);
            if(nums[l] <= nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return res;
    }
};
