class Solution {
public:
    bool dfs(int src,vector<bool>& vis,vector<bool>& RecPath,vector<vector<int>>& prerequisites){
        vis[src] = true;
        RecPath[src]=true;
        for(int i=0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u == src){
                if(!vis[v]){
                    if(dfs(v,vis,RecPath,prerequisites)) return true;
                }
                else if(RecPath[v]){
                    return true;
                }
            }
        }
        RecPath[src] = false;
        return false;
    }

    void toposort(int src,vector<bool>& vis,stack<int>& st,vector<vector<int>>& prerequisites){
        vis[src] = true;
        for(int i=0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            if(src ==  u){
                if(!vis[v]){
                    toposort(v,vis,st,prerequisites);
                }
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n,false);
        vector<bool> RecPath(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,RecPath,prerequisites)) return {};
            }
        }
        stack<int> st;
        vis.assign(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(i,vis,st,prerequisites);
            }
        }
        while(!st.empty()){
            int temp = st.top();
            ans.push_back(temp);
            st.pop();
        }
        return ans;
    }
};