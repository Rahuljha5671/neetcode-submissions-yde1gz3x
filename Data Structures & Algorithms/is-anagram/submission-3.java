class Solution {
    public boolean isAnagram(String s, String t) {

        //brute force
        //String l1=Arrays.stream(s.split("")).sorted().collect(Collectors.joining());
        //String l2=Arrays.stream(t.split("")).sorted().collect(Collectors.joining());

        // if(l1.equals(l2)){
        //     return true;
        // }
        // return false;

        //hashmap approach
        // Map<Character,Integer>mps=new HashMap<>();
        // Map<Character,Integer>mpt=new HashMap<>();

        // for(int i=0;i<s.length();i++){
        //     mps.put(s.charAt(i),mps.getOrDefault(s.charAt(i),0)+1);
        // }

        // for(int i=0;i<t.length();i++){
        //     mpt.put(t.charAt(i),mpt.getOrDefault(t.charAt(i),0)+1);
        // }

        // if(mps.equals(mpt)){
        //     return true;
        // }
        // return false;

        //hash array approach

        int[] arrs=new int[26];
        int[] arrt=new int[26];

        for(int i=0;i<26;i++){
            arrs[i]=0;
            arrt[i]=0;
        }

        for(int i=0;i<s.length();i++){
            int idx=s.charAt(i)-'a';
            arrs[idx]++;
        }
        for(int i=0;i<t.length();i++){
            int idx=t.charAt(i)-'a';
            arrt[idx]++;
        }


        if(Arrays.equals(arrs,arrt)){
            return true;
        }
        return false;





    }
}
