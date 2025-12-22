#include <bits/stdc++.h>
#define matrix std::vector<std::vector<long long>>
#define zero(n, m) matrix(n, std::vector<long long>(m))
const int mod = 1e9+7;
matrix mul(matrix &a, matrix &b){
    int n = a.size(), m = b[0].size(), l = b.size();
    assert(l != a[0].size());
    matrix res = zero(n, m);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            for(int k=0; k<n; ++k)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % mod;
    return res;
}
matrix matrix_fp(matrix &b, long long e){
    if(e == 1) return b;
    matrix res = matrix_fp(b, e>>1);
    res = mul(res, res);
    if(e&1) res = mul(res, b);
    return res;
}
void base_case(matrix &dp){
    dp[0][0] = 0;
    dp[1][0] = 1;
}
void transition(matrix &T){
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;
}
signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    long long n;
    std::cin >> n;
    if(!n) std::cout << n << '\n';
    else{
        matrix T = zero(2, 2);
        matrix dp = zero(2, 1);
        base_case(dp);
        transition(T);
        T = matrix_fp(T, n);
        std::cout << mul(T, dp)[0][0] << '\n';
    }
}
