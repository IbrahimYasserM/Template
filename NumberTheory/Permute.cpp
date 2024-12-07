long long P(int n, int r){
  if(r > n) return 0;
  return f[n] * fp(f[n-r], mod-2) % mod;
}
