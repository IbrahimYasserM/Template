struct PrefixHash {
    int B1, B2, n, *a1, *a2, *pw1, *pw2;
    static constexpr int mod{1000000007};
    PrefixHash(const std::string &s, const int b1, const int b2) : B1(b1), B2(b2), n(s.size()), a1(new int[n + 1]{}), a2(new int[n+1]{}),  pw1(new int[n + 1]{1}), pw2(new int[n + 1] {1}){
        for (int i = 1; i < n + 1; i++) {
            a1[i] = ((long long)a1[i-1]*B1%mod+s[i-1]-96)%mod;
            a2[i] = ((long long)a2[i-1]*B2%mod+s[i-1]-96)%mod;
            pw1[i] = (long long)pw1[i-1]*B1%mod;
            pw2[i] = (long long)pw2[i-1]*B2%mod;
        }
    }
    explicit PrefixHash(const std::string &s) : PrefixHash(s, 31, 37) {}
    ~PrefixHash() = default;
    [[nodiscard]] long long get(const int l, const int r) const {
        return (a1[r+1]-(long long)a1[l]*pw1[r-l+1]%mod+mod)%mod*mod+(a2[r+1]-(long long)a2[l]*pw2[r-l+1]%mod+mod)%mod;
    }
};
