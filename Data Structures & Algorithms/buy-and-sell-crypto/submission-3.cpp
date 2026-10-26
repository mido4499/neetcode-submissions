class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, res = 0;

        while (l < prices.size() && r < prices.size()){
            if (prices[r] < prices[l]){
                l = r;
                r = l+1;
                continue;
            }
            else if (prices[r] > prices[l]){
                res = max(res, prices[r]-prices[l]);
            }
            r++;
        }

        return res;
    }
};
