int *spf;
void Spf(int n){
  spf = new int[n]{};
  for(long long i=2;i<n;++i)
    if(!spf[i])
      for(long long j=i*i;j<n;j+=i)
        spf[j] = i;
}
