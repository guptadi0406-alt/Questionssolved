class Solution {
    public long appealSum(String s) {
        HashMap<Character,ArrayList<Long>> hm = new HashMap<>();

        long n = s.length();
        for(long i=0;i<n;i++){
            char a = s.charAt((int)i);
            if(!hm.containsKey(a)){
                hm.put(a,new ArrayList<>());
            }

            hm.get(a).add(i);
        }

     
        long ans = 0;
        for(ArrayList<Long> k : hm.values()){
            
            for(int i=0;i<k.size();i++){
                long left = (k.get(i)+1);
                long right = (n-k.get(i));

                ans +=(left)*(right);

                if(i+1<k.size()) ans-=(left*(n-k.get(i+1)));
            }
        }

        return ans;
    }
}