class Solution {
public:
    vector<vector<int>> adj;
    vector<int> count;
    vector<int> ans;
    int n;

    void dfs1(int node, int parent, int depth) {
        count[node] = 1;
        ans[0] += depth;

        for (int child : adj[node]) {
            if (child == parent)
                continue;

            dfs1(child, node, depth + 1);
            count[node] += count[child];
        }
    }

    void dfs2(int node, int parent) {
        for (int child : adj[node]) {
            if (child == parent)
                continue;

            ans[child] = ans[node] + n - 2 * count[child];

            dfs2(child, node);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;

        adj.resize(n);
        count.resize(n);
        ans.resize(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0, -1, 0);
        dfs2(0, -1);

        return ans;
    }
};