class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n= nums.size();
        tree.resize(4*n);

        build(0,0,n-1,nums);
    }

    void build(int node,int st,int end,vector<int>& nums){
        if(st == end){
            tree[node] = nums[st];
            return;
        }
        int mid= st+(end-st)/2;
        build(2*node+1,st,mid,nums);
        build(2*node+2,mid+1,end,nums);

        tree[node] = tree[2*node+1]+tree[2*node+2];
    }
    void updateRange(int node,int st,int end,int idx,int val){
        if(st == end){
            tree[node] = val;
            return;
        }
        int mid= st + (end-st)/2;
        if(idx <= mid){
            updateRange(2*node+1,st,mid,idx,val);
        }
        else{
            updateRange(2*node+2,mid+1,end,idx,val);
        }
        tree[node] = tree[2*node+1]+tree[2*node+2];
    }

    void update(int index, int val) {
        updateRange(0,0,n-1,index,val);
    }

    int query(int node,int st,int end,int l,int r){
        if(r < st || end < l) return 0;
        if(l <= st && end <= r) return tree[node];

        int mid = st + (end-st)/2;
        int left = query(2*node+1,st,mid,l,r);
        int right = query(2*node+2,mid+1,end,l,r);

        return left + right;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */