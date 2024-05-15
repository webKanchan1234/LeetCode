class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int>s;
        for(auto x:operations){
            if(s.empty()){
                int v=stoi(x);
                s.push(v);
            }else{
                if(x=="C"){
                    s.pop();
                }else if(x=="D"){
                    int top=s.top();
                    // s.pop();
                    top*=2;
                    s.push(top);
                }else if(x=="+"){
                    int t1=s.top();
                    s.pop();
                    int t2=s.top();
                    // s.pop();
                    s.push(t1);
                    s.push(t1+t2);
                }else{
                    int v=stoi(x);
                    s.push(v);
                }
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};