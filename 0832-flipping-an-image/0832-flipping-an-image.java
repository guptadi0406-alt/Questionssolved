class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int n = image.length;

        for(int i=0;i<n;i++){

            int k=n-1;
            int j=0;
            while(j<=k){
                int t = image[i][j];
                image[i][j]=image[i][k];
                image[i][k]=t;
                j++;k--;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    image[i][j] = 1 - image[i][j];
            }
        }

        return image;
        
    }
}