const ll inf = 1e16;
struct Edge {
    int to;
    ll cost, cap, flow;
    int backEdge;
};
struct MCMF {
    int s, t, n;
    std::vector<vector<Edge>> g;
    MCMF(int s, int t, int n) : s(s), t(t), n(n+1), g(n+1) {}
    void addEdge(int u, int v, ll cap, ll cost) {
        Edge e1 = { v, cost, cap, 0, (int)g[v].size() };
        Edge e2 = { u, -cost, 0, 0, (int)g[u].size() };
        g[u].push_back(e1); g[v].push_back(e2);
    }
    pair<ll, ll> minCostMaxFlow(ll k=inf) {
        ll flow = 0, cost = 0;
        vector<int> state(n), from(n), from_edge(n);
        vector<ll> d(n);
        deque<int> q;
        while (true) {
            for (int i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1; q.clear(); q.push_back(s); d[s] = 0;
            while (!q.empty()) {
                int v = q.front(); q.pop_front(); state[v] = 0;
                for (int i = 0; i < (int) g[v].size(); i++) {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    int to = e.to; d[to] = d[v] + e.cost;
                    from[to] = v; from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf) break;
            ll it = t, add_flow = k, add_cost = 0;
            while (it != s) {
                add_flow = min(add_flow,
                              g[from[it]][from_edge[it]].cap
                              - g[from[it]][from_edge[it]].flow);
                add_cost += g[from[it]][from_edge[it]].cost;
                it = from[it];
            }
            if (!add_flow) break;
            k -= add_flow;
            flow += add_flow;
            cost += add_flow * add_cost;
            it = t;
            while (it != s) {
                g[from[it]][from_edge[it]].flow += add_flow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= add_flow;
                it = from[it];
            }
        }
        return {cost,flow};
    }
};
