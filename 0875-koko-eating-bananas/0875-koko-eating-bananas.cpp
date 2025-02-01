class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int l=1,r=1000000000;
        while(l<r){
            long mid=l+(r-l)/2;
            int ans=0;
            for(int i=0;i<piles.size();i++){
                ans+=(piles[i]/mid)+(piles[i]%mid==0 ? 0 : 1);
            }
            if(ans<=h){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};