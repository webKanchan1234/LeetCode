class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            map<int,int>m;
            for(int j=0;j<=i;j++){
                m[A[j]]++;
            }
            int cnt=0;
            for(int j=0;j<=i;j++){
                if(m.find(B[j])!=m.end()){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};