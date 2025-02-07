class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        int n=prerequisites.size();
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indeg(numCourses);
        for(int i=0;i<adj.size();i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();

            ans.push_back(top);
            for(auto it:adj[top]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};