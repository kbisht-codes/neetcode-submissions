class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = left + 1, cprofit = 0, mprofit = 0;
        while(left < right && right < prices.size()) {
            cprofit = prices[right] - prices[left];
            mprofit = max(cprofit, mprofit);
            if(prices[right] < prices[left])
                left = right;
            right++;
        }
        return mprofit;
    }
};
