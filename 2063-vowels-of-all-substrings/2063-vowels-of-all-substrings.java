class Solution {
    public long countVowels(String word) {
        
        long n = word.length();
        long ans = 0;
        for(long i=0;i<n;i++){
            char a = word.charAt((int)i);
            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
                ans+=((n-i)*(i+1));
            }   
        }

        return ans;
    }
}