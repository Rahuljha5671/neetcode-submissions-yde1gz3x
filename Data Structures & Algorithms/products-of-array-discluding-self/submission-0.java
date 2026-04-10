class Solution {
    public int[] productExceptSelf(int[] nums) {

        int n=nums.length;

        int[] preProd=new int[n];
        int preProdCounter=1;
        for(int i=0;i<n;i++){
            preProd[i]=preProdCounter;
            preProdCounter*=nums[i];
        }


        int[] postProd=new int[n];
        int postProdCounter=1;
        

        for(int i=n-1;i>=0;i--){
            postProd[i]=postProdCounter;
            postProdCounter*=nums[i];
        }

        int ans[]=new int[n];
        for(int i=0;i<n;i++){
            ans[i]=preProd[i]*postProd[i];
        }

        return ans;



        

    }
}  
