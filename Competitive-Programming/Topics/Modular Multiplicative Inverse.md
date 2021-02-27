# Modular Multiplicative Inverse

Finding `a`<sup>`-1`</sup> such that `(a * a<sup>-1</sup>) modulo m = 1`

For `a`<sup>`-1`</sup> to exist, `a` and `m` must be coprime, `gcd(a, m) = 1`

# Finding the Modular Inverse using Fermat's little theorem and Binary Exponentiation (modulo is prime)
```cpp
ll inverse(ll n, ll modulo){
    return power(n, modulo - 2, modulo);
}
```

# Finding the Modular Inverse using Euler's Totient Function and Binary Exponentiation (modulo could be composite)
```cpp
ll inverse(ll n, ll modulo){
    return power(n, phi[modulo] - 1, modulo);
}
```

# Finding the Modular Inverse for one number (modulo is prime)
```cpp
long long inverse(ll n, ll modulo){
	if (n <= 1) return 1;
	return (modulo - modulo / n) * get_inv(modulo % n) % modulo;
}
```

# Finding the Modular Inverse for every number modulo m (m is prime)
```cpp
vector<ll>  modInv(N, 0);
modInv[1] = 1;
for(int i = 2;i < N;i++) {  // modulo is prime
    modInv[i] = (modulo - (modulo / i) * modInv[modulo % i] % modulo) % modulo;
}
```

# Finding the Modular Inverse using Extended Euclidean algorithm (m could be composite and it's faster)
```cpp
int x, y;
int g = extended_euclidean(a, m, x, y);
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}
```
