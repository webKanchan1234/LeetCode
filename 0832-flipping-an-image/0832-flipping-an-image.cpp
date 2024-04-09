class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>res;

        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=m-1;j>=0;j--){
                 v.push_back(image[i][j]);
            }
            ans.push_back(v);
        }
        
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<m;j++){
                if(ans[i][j]==1){
                    v.push_back(0);
                }else{
                    v.push_back(1);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};