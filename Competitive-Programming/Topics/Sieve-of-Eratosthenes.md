# Sieve of Eratosthenes

```cpp
const int N = 1e6 + 9;

vector<bool> isPrime(N, true);
vector<int> smallestPrimeFactor(N, 1);
vector<int> primes;
vector<vector<pair<int, int>>> primeFactorization(N);
vector<int> numDivisors(N, 1);

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    /* This loop could be optimized */
    for(int i = 2; i < N; i++) {
        if (isPrime[i]) {

            /* Keep it only if you need it */
            primes.push_back(i);

            /* This loop could be optimized */
            for (int j = i; j < N; j += i) {
                if(j != i)
                    isPrime[j] = false;

                /* Keep it only if you need it */
                smallestPrimeFactor[i] = i;

                /* Keep it only if you need it */
                int cpy = j, cnt = 0;
                while (cpy % i == 0) cpy /= i, cnt++;

                primeFactorization[j].push_back({i, cnt});
                numDivisors[j] *= (cnt + 1);
            }
        }
    }
}
```
