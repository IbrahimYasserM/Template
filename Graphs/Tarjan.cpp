int timer;
int in[N], low[N], root[N];
bool inStack[N];
std::stack<int> nodes;
std::vector<std::vector<int>> components, c_adj;
void dfs(int i, std::vector<int> adj[]) {
    in[i] = low[i] = timer++;
    inStack[i] = true;
    nodes.push(i);
    for (auto ch : adj[i]) {
        if (in[ch] == -1)
            dfs(ch, adj);
        if (inStack[ch])
            low[i] = std::min(low[i], low[ch]);
    }
    if (in[i] == low[i]) {
        components.push_back({i});
        while (!nodes.empty()) {
            int x = nodes.top();
            nodes.pop();
            root[x] = i;
            inStack[x] = false;
            if (x == i) break;
            components.back().push_back(x);
        }
    }
}
void tarjan(int n, std::vector<int> adj[]) {
    timer = 0;
    memset(in, -1, n*sizeof(in[0]));
    for (int i=0; i<n; ++i)
        if (in[i] == -1)
            dfs(i, adj);
    c_adj.assign(n, {});
    for (auto &v : components)
        for (auto u : v)
            for (auto ch : adj[u])
                if (root[u] != root[ch])
                    c_adj[root[u]].push_back(root[ch]);
}
