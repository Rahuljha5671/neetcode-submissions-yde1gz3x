class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        Map<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        List<Integer>numsCopy=new ArrayList<>();

        for(int i=0;i<n;i++){
            numsCopy.add(nums[i]);
        }

        Collections.sort(numsCopy,(a,b)->{
            // if(mp.get(a)>mp.get(b)){
            //     return -1;
            // }
            // return 1;
            return mp.get(b)-mp.get(a);
        });

        Set<Integer>st=new LinkedHashSet<>();
        for(int i=0;i<n;i++){
            st.add(numsCopy.get(i));
        }

        Iterator<Integer>iter=st.iterator();

        int []ans=new int[k];
        int count=0;
        while(iter.hasNext()){
            if(count==k){
                break;
            }
            ans[count]=iter.next();
            count++;
        }

        return ans;  
    }
}
