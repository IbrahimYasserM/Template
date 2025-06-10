struct SegmentTree {
    struct Node {
        long long val;
        long long lazy;
        bool is_lazy;
        explicit Node(long long x = 0) {
            val = x;
            lazy = 0;
            is_lazy = false;
        }
        void change(long long x, int sz) {
            val = x * sz;
            lazy = x;
            is_lazy = true;
        }
    };
    int tree_size;
    std::vector<Node> seg_data;

    explicit SegTree(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size *= 2;
        seg_data.assign(2 * tree_size, Node());
    }

    static Node merge(const Node &lf, const Node & ri) {
        Node ans = Node();
        ans.val = lf.val + ri.val;
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if(!seg_data[ni].is_lazy || rx - lx == 1) return;

        seg_data[ 2 * ni + 1].change(seg_data[ni].lazy, (rx-lx)/2);
        seg_data[ 2 * ni + 2].change(seg_data[ni].lazy, (rx-lx)/2);

        seg_data[ni].lazy = 0;
        seg_data[ni].is_lazy = false;
    }

    void Build(std::vector<int> &arr, int ni, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)arr.size())
                seg_data[ni] = Node(arr[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        Build(arr, 2 * ni + 1, lx, mid);
        Build(arr, 2 * ni + 2, mid, rx);

        seg_data[ni] = merge(seg_data[2 * ni + 1], seg_data[2 * ni + 2]);
    }
    void Build(std::vector<int> & arr) {
        Build(arr, 0, 0, tree_size);
    }

    Node get_range(int l, int r, int ni, int lx, int rx){
        propagate(ni, lx, rx);

        if(lx >= l && rx <= r)
            return seg_data[ni];
        if(rx <= l || lx >= r)
            return Node();

        int mid = (lx + rx) / 2;
        return merge(get_range(l, r, 2 * ni + 1, lx, mid), get_range(l, r, 2 * ni + 2, mid, rx));
    }
    long long get_range(int l, int r) {
        return get_range(l, r, 0, 0, tree_size).val;
    }


    void set(int l, int r, int v, int ni, int lx, int rx) {
        propagate(ni, lx, rx);

        if(lx >= l && rx <= r) {
            seg_data[ni].change(v, rx-lx);
            return;
        }
        if(rx <= l || lx >= r)
            return;

        int mid = (lx + rx) / 2;
        set(l, r, v, 2 * ni + 1, lx, mid);
        set(l, r, v, 2 * ni + 2, mid, rx);

        seg_data[ni] = merge(seg_data[2 * ni + 1], seg_data[2*ni + 2]);
    }

    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, tree_size);
    }
};
