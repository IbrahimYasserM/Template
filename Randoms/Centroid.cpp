struct Centroid {
    static const int N = 1e5;
    std::vector<int> c_adj[N], *adj;
    std::bitset<N> done;
    int sz[N], c_p[N];
    Centroid(std::vector<int> temp[]) {
        adj = temp;
        solve(0, -1);
    }
    int update_sz(int i, int p) {
        sz[i] = 1;
        for (auto ch : adj[i])
            if (ch != p && !done[ch])
                sz[i] += update_sz(ch, i);
        return sz[i];
    }
    int get_centroid(int i, int p, int n) {
        for (auto ch : adj[i])
            if (ch != p && !done[ch] && sz[ch] * 2 > n)
                return get_centroid(ch, i, n);
        return i;
    }
    void solve(int i, int p) {
        int cent = get_centroid(i, -1, update_sz(i, -1));
        done[cent] = true;
        if (~p) c_adj[p].push_back(cent);
        c_p[cent] = p;
        for (auto ch : adj[cent])
            if (!done[ch])
                solve(ch, cent);
    }
};
