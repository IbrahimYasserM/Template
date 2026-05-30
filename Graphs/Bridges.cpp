bool visited[N];
int timer, tin[N], low[N];
std::vector<std::pair<int ,int>> bridges;
void IS_BRIDGE(int x, int y) {
    if (x > y) std::swap(x, y);
    bridges.emplace_back(x, y);
}
void dfs(int v, int p, std::vector<int> adj[]) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to])
            low[v] = std::min(low[v], tin[to]);
        else {
            dfs(to, v, adj);
            low[v] = std::min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
void find_bridges(int n, std::vector<int> adj[]) {
    timer = 0;
    memset(visited, 0, n);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i, -1, adj);
}
