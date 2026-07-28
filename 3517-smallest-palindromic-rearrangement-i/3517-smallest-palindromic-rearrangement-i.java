class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();

        HashMap<Character,Integer> hm = new HashMap<>();

        for(int i=0;i<n;i++){
            hm.put(s.charAt(i),hm.getOrDefault(s.charAt(i),0)+1);
        }

        StringBuilder ns = new StringBuilder("");

        for(int i=0;i<26;i++){
                char a = (char)(i+'a');

                int q = (hm.getOrDefault(a,0))/2;

                if(hm.getOrDefault(a,0)!=1){
                    for(int j=0;j<q;j++){
                        ns.append(a);
                    }
                }
        }

         for(int i=0;i<26;i++){
                char a = (char)(i+'a');
                int q = hm.getOrDefault(a,0)%2;
                if(q==1){
                    ns.append(a);
                }
        }

         for(int i=25;i>=0;i--){
                char a = (char)(i+'a');

                int q = (hm.getOrDefault(a,0)/2);

                for(int j=0;j<q;j++){
                    ns.append(a);
                }
        }


        return ns.toString();
    }
}