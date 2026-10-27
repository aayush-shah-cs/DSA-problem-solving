class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        build(0, 0, n - 1, nums);
    }

    void build(int node, int st, int end, vector<int>& arr) {
        // Leaf node
        if (st == end) {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end - st) / 2;

        // Left child
        build(2 * node + 1, st, mid, arr);

        // Right child
        build(2 * node + 2, mid + 1, end, arr);

        // Merge
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int st, int end, int l, int r) {

        // No overlap
        if (r < st || end < l)
            return 0;

        // Complete overlap
        if (l <= st && end <= r)
            return tree[node];

        // Partial overlap
        int mid = st + (end - st) / 2;

        int left = query(2 * node + 1, st, mid, l, r);

        int right = query(2 * node + 2, mid + 1, end, l, r);

        return left + right;
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};