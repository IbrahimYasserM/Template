bool *prime;
std::vector<int>primes;
void Sieve(const int n){
    prime = new bool[n]{true,true};
    for(int i=2;i<n;++i)
        if(!prime[i]){
            for(long long j= static_cast<long long>(i)*i;j<n;j+=i)
                prime[j] = true;
            primes.push_back(i);
        }
}
