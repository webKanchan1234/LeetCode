class Solution {
public:
  
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<=s.length();j++){
                int val=stoi(s.substr(i,j-i));
                if(val>=low && val<=high){
                    ans.push_back(val);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};