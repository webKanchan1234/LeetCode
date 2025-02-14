class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dis(n,1e9);
        q.push({0,{src,0}});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int stop=top.first;
            int des=top.second.first;
            int w=top.second.second;
            if(stop>k) continue;

            for(auto it:adj[des]){
                int edjw=it.second;
                int ed=it.first;

                if(w+edjw<dis[ed]&& stop<=k){
                    dis[ed]=w+edjw;
                    q.push({stop+1,{ed,w+edjw}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};