class Solution {
public:
    bool binary(vector<int>& mat,int tar){
        int l=0;
        int h=mat.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(mat[m]==tar){
                return true;
            }else if(mat[m]<tar){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            if(binary(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};