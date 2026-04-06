class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] dist=new int[n][n];

        for(int i=0;i<n;i++){
            Arrays.fill(dist[i],Integer.MAX_VALUE);
            dist[i][i]=0;
        }

        for(int[] ed:edges){
            dist[ed[0]][ed[1]]=ed[2];
            dist[ed[1]][ed[0]]=ed[2];
        }


        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] != Integer.MAX_VALUE && 
                       dist[via][j] != Integer.MAX_VALUE &&
                       dist[i][via]+dist[via][j]<dist[i][j]){
                        dist[i][j]=dist[i][via]+dist[via][j];
                    }
                }
            }
        }

        int city=-1;
        int mx=Integer.MAX_VALUE;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i != j && dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }

            if(cnt<=mx){
                mx=cnt;
                city=i;
            }
        }

        return city;

    }
}