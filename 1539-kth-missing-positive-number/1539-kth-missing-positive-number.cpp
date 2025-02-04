class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int>s;
        for(auto x:arr){
            s.insert(x);
        }
        int i=1;
        for(i=1;i<=10000;i++){
            if(s.find(i)!=s.end()){
                continue;
            }else{
                k--;
                if(k==0){
                    break;
                }
            }
        }
        return i;
    }
};