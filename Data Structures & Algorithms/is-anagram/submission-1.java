class Solution {
    public boolean isAnagram(String s, String t) {

        String l1=Arrays.stream(s.split("")).sorted().collect(Collectors.joining());
        String l2=Arrays.stream(t.split("")).sorted().collect(Collectors.joining());
        // System.out.println(l1);

        
        if(l1.equals(l2)){
            return true;
        }
        return false;


    }
}
