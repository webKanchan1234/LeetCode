class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}

        vector<int> indeg(numCourses, 0);
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
        int cnt=0;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[top]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};