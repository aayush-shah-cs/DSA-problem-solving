class Solution {
public:
    bool dfs(int src,vector<bool>& vis,vector<bool>& RecPath,vector<vector<int>>& graph,vector<bool>& safe){
        vis[src] =true;
        RecPath[src] =true;
        for(auto v : graph[src]){
            if(!vis[v]){
                if(dfs(v,vis,RecPath,graph,safe)){
                    safe[src] = false;
                    return true;
                }
                    
            }
            else if(RecPath[v]) {
                safe[src] = false;
                return true;
            }
        }
        RecPath[src] =false;
        safe[src]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> RecPath(n,false);
        vector<bool> safe(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,RecPath,graph,safe);
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};