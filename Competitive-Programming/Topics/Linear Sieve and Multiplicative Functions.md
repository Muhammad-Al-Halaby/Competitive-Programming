# Linear Sieve and Multiplicative Functions

```cpp
vector<int> primes;
vector<bool> isPrime(N, 1);
vector<int> smallestPrimeFactor(N, 1);
vector<int> smallestPrimeFactorPower(N, 0);
vector<int> smallestPrimeFactorRaisedToPower(N, 1);
vector<int> sumOfDivisors(N, 0);
vector<int> numDivisors(N, 0);
vector<int> phi(N, 0);
vector<int> mobius(N, 0);
vector<int> squareFree; // not sorted

void linear_sieve () {
    numDivisors[1] = 1;
    sumOfDivisors[1] = 1;
    phi[1] = 1;
    mobius[1] = 1;
    squareFree.push_back(1);
    for (int i = 2; i < N; i++) {

        if (isPrime[i]) {   // i is prime
            primes.push_back(i);
            smallestPrimeFactor[i] = i;
            smallestPrimeFactorPower[i] = 1;
            smallestPrimeFactorRaisedToPower[i] = i;
            numDivisors[i] = 2;
            sumOfDivisors[i] = i + 1;
            phi[i] = i - 1;
            mobius[i] = -1;
            squareFree.push_back(i);
        }

        for (int j = 0; j < primes.size() && i * primes[j] < N; j++) {  //composite numbers
            int p = primes[j];
            int x = p * i;

            isPrime[x] = false;
            smallestPrimeFactor[x] = p;
            smallestPrimeFactorPower[x]++;
            smallestPrimeFactorRaisedToPower[x] *= p;

            if (i % p == 0) {   // i and x are not square-free, p is the smallest prime factor of i and x, gcd(i, p) != 1
                numDivisors[x] = (smallestPrimeFactorPower[i] + 2) * numDivisors[i / smallestPrimeFactorRaisedToPower[i]];
                sumOfDivisors[x] = ((smallestPrimeFactorRaisedToPower[i] * p * p - 1) / (p - 1)) * sumOfDivisors[i / smallestPrimeFactorRaisedToPower[i]];
                phi[x] = p * phi[i];
                mobius[x] = 0;
                smallestPrimeFactorPower[x] += smallestPrimeFactorPower[i];
                smallestPrimeFactorRaisedToPower[x] *= smallestPrimeFactorRaisedToPower[i];
                break;
            } else {   // i and x could be square-free, p is the smallest prime factor of x, gcd(i, p) = 1
                numDivisors[x] = numDivisors[p] * numDivisors[i];
                sumOfDivisors[x] = sumOfDivisors[p] * sumOfDivisors[i];
                phi[x] = phi[p] * phi[i];
                mobius[x] = mobius[p] * mobius[i];
                if(mobius[i])   // i and x are square-free
                    squareFree.push_back(x);
            }
        }
    }
}
```
