const int N = 10000, LG = 20;
int timer, in[N], out[N], par[N][LG], depth[N];
struct LCA {
    explicit LCA(std::vector<int> adj[], int n){
        timer = 0;
        dfs(adj);
        for(int j=1; j<LG; ++j)
            for(int i=0; i<n; ++i)
                par[i][j] = par[par[i][j-1]][j-1];
    }
    static void dfs(std::vector<int> adj[], int i=0, int p=0, int d=0) {
        in[i] = timer++;
        par[i][0] = p;
        depth[i] = d;
        for (auto ch: adj[i])
            dfs(adj, ch, i, d+1);
        out[i] = timer;
    }
    static int kth_ancestor(int x, int k){
        for(int j=0; j<LG; ++j)
            if(k&(1<<j))
                x = par[x][j];
        return x;
    }
    static bool is_parent(int x, int y) { return in[x] <= in[y] && out[x] >= out[y]; }
    static int lca(int x, int y) {
        if (is_parent(x, y)) return x;
        for (int j = LG - 1; ~j; --j)
            if (!is_parent(par[x][j], y))
                x = par[x][j];
        return par[x][0];
    }
    static int lca_d(int x, int y){
        if(depth[x] < depth[y]) std::swap(x, y);
        x = kth_ancestor(x, depth[x]-depth[y]);
        if(x == y) return x;
        for(int j=LG-1; ~j; --j)
            if(par[x][j] != par[y][j])
                x = par[x][j], y = par[y][j];
        return par[x][0];
    }
};
