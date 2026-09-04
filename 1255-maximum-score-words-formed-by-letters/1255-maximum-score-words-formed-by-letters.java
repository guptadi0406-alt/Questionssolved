class Solution {
    int max=0;
    void rec(int i , Map<Character,Integer> arr[] , Map<Character,Integer> mp , int[] score ,int cnt[],int s ){
        if(i>=arr.length){
            max=Math.max(max,s);
            return ;
        }   

        int mask = 0;

        for(char v : arr[i].keySet()){   
            if(cnt[v-'a'] + arr[i].get(v)>mp.getOrDefault(v,0)){
                mask=1;
                break;
            }
        }

        if(mask==0){
            int sc = 0;
            for(char v : arr[i].keySet()){
                    cnt[v-'a'] += arr[i].get(v);
                    sc+= (score[v-'a']*arr[i].get(v));
            }

             rec(i+1,arr,mp,score,cnt,s+sc);

             for(char v : arr[i].keySet()){
                    cnt[v-'a'] -= arr[i].get(v);
            }
        }


        rec(i+1,arr,mp,score,cnt,s);


    }
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        
        Map<Character,Integer> mp = new HashMap<>();
        int n = letters.length;
        for(int i=0;i<n;i++){
            mp.put(letters[i],mp.getOrDefault(letters[i],0)+1);
        }

        int m = words.length;
        Map<Character,Integer> arr[] = new HashMap[m];
  
        for(int i=0;i<m;i++){
           
            Map<Character,Integer> mp1 = new HashMap<>();
            int k = words[i].length();
            String s = words[i];

            for(int j=0;j<k;j++){
                mp1.put(s.charAt(j),mp1.getOrDefault(s.charAt(j),0)+1);
            }

            arr[i] = mp1;

        }

        int cnt[]= new int[26];
        rec(0,arr,mp,score,cnt,0);


        return max;

    }
}