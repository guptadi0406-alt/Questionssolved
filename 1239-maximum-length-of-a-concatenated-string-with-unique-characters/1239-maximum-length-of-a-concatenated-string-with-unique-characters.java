class Solution {
    int max = 0;
    void rec(int i , String s , List<String> arr){

        if(i==arr.size()){
            int n = s.length();
            Set<Character> st =new HashSet<>();
            for(int j=0;j<n;j++) st.add(s.charAt(j));

            if(st.size() == n){
                max=Math.max(max,n);
            }
            return ;
        }

        rec(i+1,s+arr.get(i),arr);
        rec(i+1,s,arr);

    }

    public int maxLength(List<String> arr) {
            rec(0,"",arr);

            return max;
    }
}