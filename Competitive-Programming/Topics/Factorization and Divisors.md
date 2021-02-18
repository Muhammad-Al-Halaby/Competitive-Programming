#  Factorization and Divisors

# Sieve of Eratosthenes
```cpp
const int N = 1e6 + 9;

vector<bool> isPrime(N, true);
vector<int> smallestPrimeFactor(N, 1);
vector<int> largestPrimeFactor(N, 1);
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
                largestPrimeFactor[j] = i;
                if(smallestPrimeFactor[j] == 1)
                  smallestPrimeFactor[j] = i;

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

# Count the number of prime factors after sieve in O(n)
```cpp
void countPrimeFactors() {
    sieve(); // includes calculating smallest prime factor of each number
    vector<ll> factorsCount(N, 0);
    for (int i = 2; i < N; i++)
        factorsCount[i] += factorsCount[i / smallestPrimeFactor[i]] + 1;
}
```

# Check if a single integer is prime
```cpp
bool isPrime(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0)
          return 0;
    }
    return 1;
}
```

# Factorize a a single or all integers from 1 to N (sorted)
```cpp
vector<pair<ll, int>> factors[N];

void factorize(ll n){
    auto &factors = ::factors[n];

    if(factors.size())   return;

    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0)   n /= i, cnt++;
            factors.push_back({i, cnt});
        }
    }
    if(n > 1)
        factors.push_back({n, 1});
}
```

# Factorize a single integer
```cpp
vector<pair<ll, int>> factors;

void factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0)   n /= i, cnt++;
            factors.push_back({i, cnt});
        }
    }
    if(n > 1)
        factors.push_back({n, 1});
}
```

# Factorize a single integer without powers
```cpp
vector<ll> factors;

void factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            while(n % i == 0)   n /= i;
            factors.push_back(i);
        }
    }
    if(n > 1)
        factors.push_back(n);
}
```

# Divisors of a single or all integers from 1 to N (sorted)
```cpp
vector<vector<int>> divisors(N);

void getDivisors(ll n) {
    if (divisors[n].size()) return;

    vector<int> smallDivs;
    vector<int> largeDivs;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            smallDivs.push_back(i);
            if (n / i != i)
                largeDivs.push_back(n / i);
        }
    }

    reverse(largeDivs.begin(), largeDivs.end());
    divisors[n].resize(smallDivs.size() + largeDivs.size());
    merge(smallDivs.begin(), smallDivs.end(), largeDivs.begin(), largeDivs.end(), divisors[n].begin());
}
```

# Divisors of all integers from 1 to N (Preprocessing)
```cpp
const int N = 1e5 + 9;

vector<vector<int>> divisors(N);

void getDivisors(){
    for(int i = 1;i < N;i++){
        for(int j = 1;j * j <= i;j++) {
            if (i % j == 0) {
                divisors[i].push_back(j);
                if (i / j != j)
                    divisors[i].push_back(i / j);
            }
        }
    }
}
```


# Divisors of a single integer
```cpp
vector<ll> divisors;

void getDivisors(ll n){
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n / i != i)
                divisors.push_back(n / i);
        }
    }
}
```

# Prime factorization of n!
Given all primes less than n, we need to calculate the power of each prime factor in `n!`

For each prime factor `p^x` -> `x = n/p^1 + n/p^2 + n/p^3 + ...`

```cpp
for(auto p : primes) {
    int exponent = 0;
    while (n) {
        n /= p;
        exponent += n;
    }
}
```
