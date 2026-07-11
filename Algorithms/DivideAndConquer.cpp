#include <bits/stdc++.h>
signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int a[n];
    long long p[n];
    for (int i=0; i<n; ++i) {
        std::cin >> a[i];
        p[i] = a[i] + (i?p[i-1]:0);
    }
    auto C = [&](int l, int r) {
        long long sum = (r?p[r-1]:0) - (l?p[l-1]:0);
        return sum*sum;
    };
    std::vector<long long> ldp(n+1, 5e17), dp(n+1);
    ldp[0] = 0;
    std::function<void(int, int, int, int)> solve = [&](int l, int r, int ll, int lr) {
        if (l>r) return;
        int m = (l+r)/2;
        std::pair<long long, int> best = {5e17, -1};
        for (int k=ll; k<=std::min(m, lr); ++k)
            best = std::min(best, {ldp[k]+C(k, m), k});
        dp[m] = best.first;
        int opt = best.second;
        solve(l, m-1, ll, opt);
        solve(m+1, r, opt, lr);
    };
    while (k--) {
        solve(0, n, 0, n);
        ldp = dp;
    }
    std::cout << ldp[n] << '\n';
