# Euler's totient function


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
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```

## Modular Exponentatioan using Euler's theorem:
This allows computing x<sup>n</sup> mod m for very big n, especially if n is the result of another computation, as it allows to compute n under a modulo.

# x<sup>n</sup> ≡ x<sup>ϕ(m) + [n mod ϕ(m)]</sup> mod m
