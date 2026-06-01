struct KuhnMatching {
    static const int N = 500, M = 500;
    std::vector<int> mt;
    std::vector<bool> used;
    KuhnMatching(int n, int m, std::vector<int> adj[]) {
        mt.assign(m, -1);
        int ans{};
        for (int v=0; v<n; ++v) {
            used.assign(n, false);
            ans += try_kuhn(v, adj);
        }
        std::cout << ans << '\n';
        for (int i=0; i<m; ++i)
            if (~mt[i])
                std::cout << mt[i]+1 << ' ' << i+1 << '\n';
    }
    bool try_kuhn(int v, std::vector<int> adj[]) {
        if (used[v])
            return false;
        used[v] = true;
        for (int to : adj[v]) {
            if (mt[to] == -1 || try_kuhn(mt[to], adj)) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }
};
