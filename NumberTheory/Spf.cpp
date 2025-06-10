int *spf;
void Spf(const int n){
    spf = new int[n]{};
    for(int i=2;i<n;++i)
        if(!spf[i])
            for(long long j= static_cast<long long>(i) *i;j<n;j+=i)
                spf[j] = i;
}
