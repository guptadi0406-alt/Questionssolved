class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;

        if(n==0) return arr;
        int []copyarr=new int[n];

        for(int i=0;i<n;i++){
            copyarr[i]=arr[i];
        }

        Arrays.sort(arr);


        HashMap<Integer,Integer> hm =new HashMap<>();

        int flag=1;
        hm.put(arr[0],flag);
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]){
                hm.put(arr[i],flag);
            }else {
                flag++;
                hm.put(arr[i],flag);
            }
        }


        // System.out.println(Arrays.toString(arr));

        int ans []=new int[n];
       
        for(int i=0;i<n;i++){
            ans[i] = hm.get(copyarr[i]);
        }

        return ans;


    }
}