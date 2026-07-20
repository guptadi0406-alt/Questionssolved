class Solution {
    public int uniqueLetterString(String s) {

        HashMap<Character,ArrayList<Integer>> hm = new HashMap<>();

        int n = s.length();
        for(int i=0;i<n;i++){
            char a = s.charAt(i);
            if(!hm.containsKey(a)){
                hm.put(a,new ArrayList<>());
            }

            hm.get(a).add(i);
        }




        // System.out.println(hm);

        int ans = 0;

        for(ArrayList<Integer> k : hm.values()){

            for(int i=0;i<k.size();i++){

                if(i+1<k.size() && i-1>=0){
                    int left = (k.get(i)-k.get(i-1));
                    int right = (k.get(i+1)-k.get(i));
                    ans += (left*right);
                    
                }else if(i+1<k.size()){
                    int left = (k.get(i)+1);
                    int right = (k.get(i+1)-k.get(i));
                    ans += (left*right);

                }else if(i-1>=0){
                    int left = (k.get(i)-k.get(i-1));
                    int right = (n-k.get(i));
                    ans += (left*right);
                }else{
                    int left = (k.get(i)+1);
                    int right = (n-k.get(i));
                    ans += (left*right);
                }

            }
        }
      

        return ans;
    }
}