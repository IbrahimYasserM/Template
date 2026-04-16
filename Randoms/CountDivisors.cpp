// Sardina
// Time Complexity: O(Cubic Root(N))
// Needs Miller-Rabin
bool is_prime_square(int n)
{
    int num = sqrtl(n);
    return num * num == n && MillerRabin(num);
}
int count_divisors(int n)
{
    // can also be used to get:
    // sum and product of the divisors
    int ans = 1;
    for (auto &p : primes)
    {
        if (p * p * p > n)
            break;
        if (n % p != 0)
            continue;
        int cnt = 0;
        while (n % p == 0)
        {
            cnt++;
            n /= p;
        }
        ans *= (cnt + 1);
    }
    if (MillerRabin(n))
        ans *= 2;
    else if (is_prime_square(n))
        ans *= 3;
    else if (n != 1)
        ans *= 4;
    return ans;
}