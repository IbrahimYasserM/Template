long long C(int n, int r){
  if(r > n || r < 0) return 0;
  return f[n] * (Fp(f[r], mod-2) * Fp(f[n-r], mod-2) % mod) % mod;
}
