class Solution {
public:

    int calculate(vector<int>& piles,int banana){

        long long hours_taken=0;

        for(int i=0;i<piles.size();i++){
            double hour=(double)piles[i]/banana;
            hours_taken+=ceil(hour);
        }
        return hours_taken;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int high=INT_MIN;
        int low=1;
        int ans;
        
        for(int p:piles){
            high=max(high,p);
        }

        int hours_taken=0;

        while(low<=high){
            int mid=(low+high)/2;
            cout<<"mid="<<mid<<" ";

            hours_taken=calculate(piles,mid);
            cout<<"hours_taken="<<hours_taken<<endl;

            if(hours_taken<=h){
                high=mid-1;
                ans=mid;
                cout<<ans<<endl;
            }
            else{
                low=mid+1;
            }
        }

        return ans; 
    }
};
