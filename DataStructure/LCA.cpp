const int N = 10000, LG = 20;
int timer, in[N], out[N], p[N][LG];
struct LCA {
  explicit LCA(std::vector<int> adj[], int n){
    timer = 0;
    dfs(adj);
    for(int j=1; j<LG; ++j)
      for(int i=0; i<n; ++i)
        p[i][j] = p[p[i][j-1]][j-1];
  }
  void dfs(std::vector<int> adj[], int i=0, int P=0) {
    in[i] = timer++;
    p[i][0] = P;
    for (auto ch: adj[i])
      dfs(adj, ch, i);
    out[i] = timer;
  }
  bool is_parent(int x, int y) { return in[x] <= in[y] && out[x] >= out[y]; }
  int lca(int x, int y) {
    if (is_parent(x, y)) return x;
    for (int j = LG - 1; ~j; --j)
      if (!is_parent(p[x][j], y))
        x = p[x][j];
    return p[x][0];
  }
};