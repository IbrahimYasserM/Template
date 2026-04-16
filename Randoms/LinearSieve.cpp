// Sardina
// Time Complexity : O(N)
const int N=1e5+1;
bitset<N>notprime;
vector<int>primes;
void linear_sieve(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<N;i++){
        if(!notprime[i])primes.pb(i);
        for(auto it:primes){
            if(it*i>=N)break;
            notprime[i*it]=1;
            if(i%it==0)break;
        }
    }
}