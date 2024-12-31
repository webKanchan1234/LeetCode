class Solution {
public:
    bool helper(int m, int n, int d){
        // if(d>max(m,n)){
        //     return false;
        // }
        queue<vector<int>>q;
        vector<vector<int>>vis(m+1,vector<int>(n+1,false));
        q.push({0,0});
        while(!q.empty()){
            vector<int> curr=q.front();
            int j1=curr[0];
            int j2=curr[1];
            q.pop();
            if(j1==d || j2==d || j1+j2==d){
                return true;
            }
            //fill j1
            if(!vis[m][j2]){
                vis[m][j2]=true;
                q.push({m,j2});
            }

            //fill j2
            if(!vis[j1][n]){
                vis[j1][n]=true;
                q.push({j1,n});
            }

            //empty j1
            if(!vis[0][j2]){
                vis[0][j2]=true;
                q.push({0,j2});
            }

            //empty j2
            if(!vis[j1][0]){
                vis[j1][0]=true;
                q.push({j1,0});
            }

            //pour j1 to j2
            int j1toj2=min(j1,n-j2);
            if(!vis[j1-j1toj2][j2+j1toj2]){
                vis[j1-j1toj2][j2+j1toj2]=true;
                q.push({j1-j1toj2,j2+j1toj2});
            }

            //pour j2 to j1
            int j2toj1=min(j2,m-j1);
            if(!vis[j1+j2toj1][j2-j2toj1]){
                vis[j1+j2toj1][j2-j2toj1]=true;
                q.push({j1+j2toj1,j2-j2toj1});
            }
        }
        return false;
    }
    bool canMeasureWater(int x, int y, int target) {
        return helper(x,y,target);
    }
};