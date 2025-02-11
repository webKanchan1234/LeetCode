class Solution {
public:
    int getmaxidx(vector<vector<int>>& mat,int n, int m, int c){
        int mx=-1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][c]>mx){
                mx=mat[i][c];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        vector<int>ans;
        while(l<=h){
            int mid=(l+h)/2;
            int mxrowindx=getmaxidx(mat,n,m,mid);

            int left=mid-1>=0 ? mat[mxrowindx][mid-1] : -1;
            int right=mid+1<m ? mat[mxrowindx][mid+1] : -1;

            if(mat[mxrowindx][mid]>left && mat[mxrowindx][mid]>right){
                return {mxrowindx,mid};
            }else if(mat[mxrowindx][mid]<left){
                h=mid+1;
            }else{
                l=mid-1;
            }
        }
        return {-1,-1};
    }
};