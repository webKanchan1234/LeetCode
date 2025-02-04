class Solution {
public:
    int dayreq(vector<int>& weights, int w){
        int load=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>w){
                d=d+1;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=0;
        int h=0;
        int l=*max_element(weights.begin(),weights.end());

        for(int i=0;i<n;i++){
            h+=weights[i];
        }
        while(l<=h){
            int m=(l+h)/2;
            int d=dayreq(weights,m);
            if(d<=days){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};