class Solution {
public:
    int findMin(vector<int> &nums) {

        int n=nums.size();
        int l=0;
        int h=n-1;


        if(nums[h]>nums[l]){
            return nums[l];
        }

        while(l<h){
            int mid=(l+h)/2;

            if(nums[mid]>=nums[0]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }

        return nums[l];
        
    }
};
