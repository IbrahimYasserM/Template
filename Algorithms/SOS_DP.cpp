void SOS_DP(){
    const int LG = 20, N = 1<<LG;
    int dp[N];
    for(int i=0; i<LG; ++i)
        for(int mask=0; mask<N; ++mask)
            if(mask&(1<<i))
                dp[mask] = dp[mask] + dp[mask^(1<<i)];
}
