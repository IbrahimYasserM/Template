long long P(int n, int r){
  if(r > n || r < 0) return 0;
  return f[n] * Fp(f[n-r], mod-2) % mod;
}
