bool visited[N];
int timer, tin[N], low[N];
std::vector<std::string> cut_points;
void dfs(int v, int p, std::vector<int> adj[]) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false, is_cut = false;
    int childs{};
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
            if (low[to] >= tin[v] && ~p)
                is_cut = true;
            ++childs;
        }
    }
    if (p == -1 && childs > 1)
        is_cut = true;
    if (is_cut)
        cut_points.push_back(s[v]);
}
void find_cutpoints(int n, std::vector<int> adj[]) {
    timer = 0;
    memset(visited, 0, n);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i, -1, adj);
}
