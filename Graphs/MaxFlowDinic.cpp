// O(E * V^2) sometimes O(E * V)
// if Unit network: O(E * sqrt(E)) O(E * V^(2/3))
// if in/out degree == 1: O(E * sqrt(V))
struct FlowEdge {
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
const ll flow_inf = 1e18;

struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll c) {
        if (c == 0 || v == t)
            return c;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            ll tr = dfs(u, min(c, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll c = dfs(s, flow_inf))
                f += c;
        }
        return f;
    }

    vector<pair<vector<int>, ll>> get_paths() {
        vector<ll> f(m);
        for (int i = 0; i < m; i++) f[i] = max(edges[i].flow, 0LL);

        vector<pair<vector<int>, ll>> res;
        while (true) {
            vector<int> par(n, -1), path_edges;
            vector<int> stk = {s};
            par[s] = -2;
            while (!stk.empty() && par[t] == -1) {
                int v = stk.back(); stk.pop_back();
                for (int id : adj[v]) {
                    int u = edges[id].u;
                    if (f[id] > 0 && par[u] == -1) { par[u] = id; stk.push_back(u); }
                }
            }
            if (par[t] == -1) break;

            ll bn = flow_inf;
            for (int v = t; v != s; v = edges[par[v]].v) bn = min(bn, f[par[v]]);
            vector<int> verts = {t};
            for (int v = t; v != s; v = edges[par[v]].v) {
                f[par[v]] -= bn;
                verts.push_back(edges[par[v]].v);
            }
            reverse(verts.begin(), verts.end());
            res.emplace_back(verts, bn);
        }
        return res;
    }
};
