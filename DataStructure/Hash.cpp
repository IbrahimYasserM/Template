struct Hash{
    int B, n;
    long long a;
    static constexpr int mod = 1e9+7, Y = 'a';
    static long long Fp(long long b, int e){
        long long ans=1;
        while(e){
            if(e&1) ans = ans * b % mod;
            b = b * b % mod;
            e>>=1;
        }
        return ans;
    }
    explicit Hash(const int b=31){
        a = 0;
        n = 0;
        B = b;
    }
    explicit Hash(const std::string &s, const int b=31) : Hash(31) {
        for (auto &c: s)
            push_back(c);
    };
    void push_back(const char c){
        a = (a * B % mod + c - Y) % mod;
        ++n;
    }
    void pop_back(const char c){
        if(!n) return;
        a = (a - c + Y + mod) % mod;
        a = a * Fp(B, mod-2);
        --n;
    }
    void push_front(const char c){
        a = (a + (c-Y)*Fp(B, n)%mod) % mod;
        ++n;
    }
    void pop_front(const char c){
        if(!n) return;
        --n;
        a = (a - (c-Y)*Fp(B, n)%mod + mod) % mod;
    }
};
