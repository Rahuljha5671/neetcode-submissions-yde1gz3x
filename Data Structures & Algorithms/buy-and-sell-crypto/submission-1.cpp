class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int maxProfit=INT_MIN;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         maxProfit=max(maxProfit,prices[j]-prices[i]);
        //     }
        // }

        // if(maxProfit<0){
        //     return 0;
        // }

        int maxi=prices[n-1];

        for(int i=n-2;i>=0;i--){
            maxProfit=max(maxProfit,maxi-prices[i]);
            maxi=max(maxi,prices[i]);

        }

        if(maxProfit<0){
            return 0;
        }
        return maxProfit;
        
    }
};
