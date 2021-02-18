# Euler's Totient Function

Euler's Totient Function `EFT(n)` or `Phi(n)` is the number of integers in the range `[1, n]` coprime with `n`

Phi is a multiplicative function.

###### ϕ(p) = p - 1

###### ϕ(p<sup>k</sup>) = p<sup>k</sup> - all multiples of p in the range [1, p<sup>k</sup>] = p<sup>k</sup> - p<sup>k</sup>/p = p<sup>k</sup> - p<sup>k-1</sup> = p<sup>k</sup> (1 - 1/p)



###### ϕ(p<sub>1</sub><sup>k<sub>1</sub></sup> * p<sub>2</sub><sup>k<sub>2</sub></sup> * p<sub>3</sub><sup>k<sub>3</sub></sup>) = (p<sub>1</sub><sup>k<sub>1</sub></sup> - p<sub>1</sub><sup>k<sub>1</sub>-1</sup>) * (p<sub>2</sub><sup>k<sub>2</sub></sup> - p<sub>2</sub><sup>k<sub>2</sub>-1</sup>) * (p<sub>3</sub><sup>k<sub>3</sub></sup> - p<sub>3</sub><sup>k<sub>3</sub>-1</sup>)

###### ϕ(a * b) = ϕ(a) * ϕ(b) iff gcd(a, b) = 1

###### ϕ(a * b)= ϕ(a) * ϕ(b) * d / ϕ(d) if a and b aren't coprime and d = gcd(a, b)

![ϕ(n)](ϕ(n).png "ϕ(n)")

###### Sum of Euler Phi Function over Divisors of n = n

###### Proved Fact: 2 * ϕ(ϕ(n)) <= n


# Phi can be calculated efficiently for all numbers `[1, n]` using linear sieve.

# Phi using factorization in O(sqrt(n))
```cpp
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
```

# Phi of all numbers from 1 to n in O(n log log n)
```cpp
int n = 1e6;
vector<int> phi(n + 1);
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {  // i is prime
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```


# Phi of all numbers from 1 to n in O(n log n)
```cpp
int n = 1e6;
vector<int> phi(n + 1);
void phi_1_to_n(int n) {
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
```

# Euler's Theorem and Modular Exponentiation

Euler's Theorem states that `a`<sup>`ϕ(m)`</sup>`≡ 1 mod m if gcd(a, m) = 1`

By utilizing this fact we get:

#### x<sup>n</sup> ≡ x<sup>n mod ϕ(m)</sup> mod m

This allows computing `x`<sup>`n`</sup> `mod m` for very big `n`, especially if `n` is the result of another computation, as it allows to compute `n` under a modulo.

### Generalization (`x` and `m` don't' have to be coprime):

#### x<sup>n</sup> ≡ x<sup>ϕ(m) + [n mod ϕ(m)]</sup> mod m

##### Problem: Count the numbers i in the interval [1, n] such that gcd(i, n) = g, ans = phi(n / g)

Proof:

Since the desired gcd = g, the only candidates are the multiples of g on the form g * x where g * x lies in the range[1, n], x lies in range [1, n / g]

n itself must be a multiple of g, n = g * y, y = n / g

Since we want gcd(n, i) = gcd(g * y, g * x) = g * gcd(x, y) = g

Then gcd(x, y) must equal 1

The problem is now is equivalent to finding the number of integers in the interval [1, n / g] which are coprime with y

since y = n / g, the answer is phi(y) = phi(n / g)


##### Problem: Given two numbers a and b, count the numbers in the interval [b, b + a - 1] which are coprime with a (Hint: Euclidean algorithm | Modular Cycles), ans = phi(a)


# Problems

- http://acm.hdu.edu.cn/showproblem.php?pid=1695

- https://codeforces.com/problemset/problem/776/E

- https://www.codechef.com/problems/SMPLSUM
