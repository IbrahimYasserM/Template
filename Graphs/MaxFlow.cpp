// O(E * F), O(V * E^2)
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
            auto [x, f] = q.front();
            q.pop();

            for (auto ch : adj[x])
                if (p[ch] == -1 && c[x][ch]) {
                    p[ch] = x;
                    int nf = std::min(f, c[x][ch]);
                    if (ch == t)
                        return nf;
                    q.emplace(ch, nf);
                }
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        long long f = 0;
        std::vector<int> p(n);
        int nf;
        while ((nf = bfs(s, t, p))) {
            f += nf;
            int x = t;
            while (x != s) {
                int y = p[x];
                c[y][x] -= nf;
                c[x][y] += nf;
                x = y;
            }
        }
        return f;
    }

    void add_edge(int x, int y, int cap) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        c[x][y] = cap;
    }
};
