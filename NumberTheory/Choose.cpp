long long C(int n, int r){
  if(r > n) return 0;
  return f[n] * (fp(f[r], mod-2) * fp(f[n-r], mod-2) % mod) % mod;
}
