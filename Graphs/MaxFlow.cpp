struct MaxFlow {
    static const int N = ;
    std::vector<int> adj[N];
    int n, c[N][N]{};
    MaxFlow(int n) : n(n){}
    int bfs(int s, int t, std::vector<int>& p) {
        std::fill(p.begin(), p.end(), -1);
        p[s] = -2;
        std::queue<std::pair<int, int>> q;
        q.emplace(s, 1e9);

        while (!q.empty()) {
            auto [x, flow] = q.front();
            q.pop();

            for (auto ch : adj[x])
                if (p[ch] == -1 && c[x][ch]) {
                    p[ch] = x;
                    int new_flow = std::min(flow, c[x][ch]);
                    if (ch == t)
                        return new_flow;
                    q.emplace(ch, new_flow);
                }
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        long long flow = 0;
        std::vector<int> p(n);
        int new_flow;
        while ((new_flow = bfs(s, t, p))) {
            flow += new_flow;
            int x = t;
            while (x != s) {
                int y = p[x];
                c[y][x] -= new_flow;
                c[x][y] += new_flow;
                x = y;
            }
        }
        return flow;
    }

    void add_edge(int x, int y, int cap) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        c[x][y] = cap;
    }
};
