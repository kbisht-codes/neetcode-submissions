class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, area = 0, ans = 0;
        while(l < r) {
            area = (r - l) * min(heights[l], heights[r]);
            ans = max(area, ans);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
