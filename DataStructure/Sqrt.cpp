struct Sqrt{
    long long *a, *b;
    int SQ;
    explicit Sqrt(int n){
        SQ = (int)sqrt(n) + 1;
        a = new long long[n]{};
        b = new long long[SQ]{};
    }
    ~Sqrt() = default;
    void set(int i, int v) const {
        b[i/SQ] -= a[i];
        a[i] = v;
        b[i/SQ] += a[i];
    }
    [[nodiscard]] long long get(int r) const{
        long long sum=0;
        for(int i=0;i<r/SQ;++i)
            sum += b[i];
        for(int i=r/SQ*SQ;i<=r;++i)
            sum += a[i];
        return sum;
    }
    [[nodiscard]] long long get(int l, int r) const{
        return get(r) - get(l-1);
    }
};
