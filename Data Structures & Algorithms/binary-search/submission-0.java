class Solution {
    public int search(int[] nums, int target) {

        int l=0;
        int h=nums.length-1;
        int ans=-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(nums[mid]==target){
                ans=mid;
                break;
            }
            
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        return ans;


        
    }
}
