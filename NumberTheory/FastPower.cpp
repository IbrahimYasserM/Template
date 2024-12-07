long long fp(long long b, int e){
  long long ans=1;
  while(e){
    if(e&1) ans = ans*b%mod;
    b = b*b%mod;
    e>>=1;
  }
  return ans;
}
