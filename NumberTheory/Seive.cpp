bool *prime;
std::vector<int>primes;
void Seive(int n){
  prime = new bool[n]{1,1};
  for(long long i=2;i<n;++i)
    if(!prime[i]){
      for(long long j=i*i;j<n;j+=i)
        prime[j] = true;
      primes.push_back(i);
    }
}
