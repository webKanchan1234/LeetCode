class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
    if(s.size()!=goal.size()){
        return false;
    }
    char temp;
    for(int i=0;i<n;i++){
        temp=goal[0];
        for(int j=0;j<n-1;j++){
            goal[j]=goal[j+1];
        }
        goal[n-1]=temp;
        if(s==goal){
            return true;
        }

    }
    return false;
    }
};