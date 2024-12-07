long long *f;
void Factorial(int n){
  f = new long long[n]{1};
  for(int i=1;i<n;++i)
    f[i] = f[i-1]*i%mod;
}
