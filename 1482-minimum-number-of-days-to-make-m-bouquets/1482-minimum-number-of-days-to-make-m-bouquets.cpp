class Solution {
public:
    bool possible(int day,int m,int k,vector<int>& bloomDay){
        int cnt=0;
        int num=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                num+=(cnt/k);
                cnt=0;
            }
        }
        num+=cnt/k;
        return num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;

        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,m,k,bloomDay)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(l>0){
            return l;
        }
        return -1;
    }

};