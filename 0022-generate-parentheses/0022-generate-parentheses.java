class Solution {
    public List<String> generateParenthesis(int n) {
        
        List<List<String>> l=new ArrayList<>();

        List<String> ans=new ArrayList<>();
        ans.add("()");

        l.add(ans);

       

        for(int i=1;i<n;i++){
           
            List<String> a=new ArrayList<>();
            List<String> x=l.get(i-1);

            HashSet<String> hs = new HashSet<>();
            for(int j=0;j<x.size();j++){
                String s=x.get(j);

                for(int k=0;k<s.length();k++){
                    String ss=s.substring(0,k);
                    String se=s.substring(k,s.length());

                    hs.add(ss+"()"+se);

                }

            }
            // System.out.println(hs);

            for(String z: hs){
                a.add(z);
            }

            l.add(a);
        }

        return l.get(n-1);

    }
}