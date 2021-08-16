#include<bits/stdc++.h>
using namespace std;

const int LIMIT = 10000;
 
int sieve[LIMIT + 1]; //In sieve lowest prime factor is stored.
int primes[LIMIT + 1];  //All primes less than LIMIT== {0.2.3.5.7.11}
int L[LIMIT+1];
int primeCount = 1;
 
void gensieve() {
    for(int i=0;i<LIMIT;i++)
        sieve[i]=0;
    for (int i = 2; i <= LIMIT; i++) {
        if (!sieve[i]) {
            primes[primeCount] = i;
            sieve[i] = primeCount++;
        }
        for (int j = 1; j <= sieve[i] && i * primes[j] <= LIMIT; j++) 
            sieve[i * primes[j]] = j;
    }
}







int main(){
    gensieve();
    for(int i=0;i<primeCount;i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<LIMIT;i++){
        cout<<primes[sieve[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
