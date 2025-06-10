struct PrefixHash {
    int B, n, *a, *pw;
    static constexpr int mod{1000000007};
    PrefixHash(const std::string &s, const int b) : B(b), n(s.size()), a(new int[n + 1]{}), pw(new int[n + 1]{1}) {
        for (int i = 1; i < n + 1; i++) {
            a[i] = ((long long)a[i-1]*B%mod+s[i-1]-96)%mod;
            pw[i] = (long long)pw[i-1]*B%mod;
        }
    }
    explicit PrefixHash(const std::string &s) : PrefixHash(s, 31) {}
    ~PrefixHash() = default;
    [[nodiscard]] int get(const int l, const int r) const {
        return (a[r+1]-(long long)a[l]*pw[r-l+1]%mod+mod)%mod;
    }
};
