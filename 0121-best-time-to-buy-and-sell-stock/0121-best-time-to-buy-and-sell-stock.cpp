class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int maxprofit=0;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_price){
                min_price=prices[i];
            }
            maxprofit=max(maxprofit,prices[i]-min_price);
        }
        return maxprofit;

    }
};