class Solution {
    public boolean hasDuplicate(int[] nums) {

        boolean hasdup=false;
        Map<Integer,Boolean>mp=new HashMap<>();

        for(int i=0;i<nums.length;i++){

            if(mp.containsKey(nums[i])){
                hasdup=true;
                break;
            }

            mp.put(nums[i],true);

        }

        return hasdup;


        
    }
}