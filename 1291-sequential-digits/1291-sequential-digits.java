class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> l = new ArrayList<>();
        String s = "123456789";

        int n = s.length();
        for(int i=0;i<n;i++){
            StringBuilder s2=new StringBuilder("");

            s2.append(s.charAt(i));
            for(int j=i+1;j<n;j++){
                  s2.append(s.charAt(j));
      
                int no = Integer.parseInt(s2.toString());
                if(no>=low && no<=high){
                    l.add(no);
                }
            }
        }

         Collections.sort(l); 

        return l;
    }
}