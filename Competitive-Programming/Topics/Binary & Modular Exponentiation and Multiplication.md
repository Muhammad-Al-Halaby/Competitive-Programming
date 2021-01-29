# Binary & Modular Exponentiation and Multiplication


## Multiplication with mod (a bit slow)
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mulmod(ll a,ll b,ll mod) {
    ll x = 0, y = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
```

## Modular Exponentiation

## Recursive
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll b, ll p, ll mod){
   if(p == 0)return 1;
   ll res = power(b,p/2);
   res *= res;
   //res %= mod;
   if(p & 1)res *= b;
   return res;// % mod;
}
```

## Iterative
```cpp
ll power(ll base, ll exponent, ll mod) {
    base %= mod;
    ll res = 1;
    while (exponent) {
        if (exponent & 1) res = (res * base) % mod;
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
```

## Modular Exponentatioan using Euler's theorem:
This allows computing x<sup>n</sup> mod m for very big n, especially if n is the result of another computation, as it allows to compute n under a modulo.

## x<sup>n</sup> ≡ x<sup>ϕ(m) + [n mod ϕ(m)]</sup> mod m
