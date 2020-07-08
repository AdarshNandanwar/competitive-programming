// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int right = n-1, left = n-1, ans = 0;
        for(int i = n-2; i>=0; i--){
            if(prices[i] <= prices[i+1]) left = i;
            else {
                ans += (prices[right]-prices[left]);
                right = left = i;
            }
        }
        ans += (prices[right]-prices[left]);
        return ans;
    }
};