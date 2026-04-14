struct HLD {
    std::vector<int> in, out, sz, par, big, head;
    int timer{};
    HLD(int n, std::vector<int> adj[]) : in(n), out(n), sz(n, 1), par(n), big(n), head(n) {
        dfs(0, adj);
        flatten(0, adj);
    }
    void dfs(int i, std::vector<int> adj[]) {
        for (auto ch : adj[i])
            if (ch != par[i]) {
                par[ch] = i;
                dfs(ch, adj);
                sz[i] += sz[ch];
                if (!big[i] || sz[ch] > sz[big[i]])
                    big[i] = ch;
            }
    }
    void flatten(int i, std::vector<int> adj[]) {
        in[i] = timer++;
        if (big[i]) {
            head[big[i]] = head[i];
            flatten(big[i], adj);
        }
        for (auto ch : adj[i])
            if (ch != par[i] && ch != big[i]) {
                head[ch] = ch;
                flatten(ch, adj);
            }
        out[i] = timer;
    }
    std::vector<std::pair<int, int>> get_path(int x, int y) {
        std::vector<std::pair<int, int>> ranges;
        while (head[x] != head[y]) {
            if (in[x] > in[y]) std::swap(x, y);
            ranges.emplace_back(in[head[y]], in[y]);
            y = par[head[y]];
        }
        if (in[x] > in[y]) std::swap(x, y);
        ranges.emplace_back(in[x], in[y]);
        return ranges; // return x if you want the lca
    }
};
