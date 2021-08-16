void SieveOfEratosthenes(long long int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (long long int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (long long int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Prlong long int all prime numbers
    for (long long int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}