class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0;
        int r=people.size()-1;
        sort(people.begin(),people.end());
        int cnt=0;
        while(l<=r){
            if(people[l]+people[r]<=limit){
                l++;
            }
            r--;
            cnt++;
        }
        return cnt;
    }
};