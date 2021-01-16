# Binomial Coefficients

# Iterative nCk (n choose k)
```cpp
ll iterative_nCk(ll n, ll k){
    ll ret = 1;
    for(ll i = k + 1;i <= n;i++){
        ll d = (i - k);
        ll q = i / d;
        ll r = i - q * d;
        ret = ret * q + ret * r / d;
    }
    return ret;
}
```

# Iterative nPr (n permute r)
```cpp
ll iterative_nPr(int n, int r){
    if(r > n)   return 0;
    ll ret = 1;
    for(int i = (n - r + 1);i <= n;i++)
        ret *= i;
    return ret;
}
```

# nCK and nPr with preprocessing
```cpp
#define modulo ll (1e9 + 7)

const int N = 1e5 + 9;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

ll inverse(ll n){
    return power(n, modulo - 2, modulo);
}

ll factorial[N], inv[N];

ll nCk(int n, int k){
    if(k > n)   return 0;
    return (((factorial[n] * inv[k]) % modulo) * inv[n - k]) % modulo;
}

ll nPr(int n, int r){
    if(r > n)   return 0;
    return (factorial[n] * inv[n - r]) % modulo;
}

void init(){
	factorial[0] = 1;
	inv[0] = inverse(1);
	for (int i = 1; i < N; i++) {
			factorial[i] = (factorial[i - 1] * i) % modulo;
			inv[i] = inverse(factorial[i]);
	}
}

int main() {
	init();

}
```



# Stars and bars:
The number of ways to put n (stars) identical objects into k (bars) labeled boxes is (n + k - 1)C(n)
