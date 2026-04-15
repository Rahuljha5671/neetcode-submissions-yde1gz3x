class Solution {
public:

    int findPivot(vector<int>& nums){

        int n=nums.size();

        int l=0;
        int h=n-1;

        while(l<h){

            int mid=(l+h)/2;

            if(nums[mid]>=nums[0]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }

        return l;
    }
    int binarySearch(vector<int>& nums,int s,int e,int target){
        
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {

        int n=nums.size();

        int l=0;
        int h=n-1;

        int pivot=findPivot(nums);
        cout<<pivot<<endl;
        int ans=-1;

        if(target>=nums[pivot] && target<nums[0]){
            ans=binarySearch(nums,pivot,n-1,target);
        }
        else{
            ans=binarySearch(nums,0,pivot,target);
        }
        return ans;
    }
};
