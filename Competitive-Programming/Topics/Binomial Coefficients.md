# Binomial Coefficients

# Code for N choose K
```cpp
ll iterativeChoose(ll n, ll k){
	if(k > n)   return 0;
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


# Code for N choose K with preprocessing
```cpp
#define modulo ll (1e9 + 7)

const int N = 1e5 + 9;

ll factorial[N];

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}

ll modInverse(ll n){
    return power(n, modulo - 2);
}

ll nCk(int n, int k){
    if(k > n)   return 0;
    return ((factorial[n] * modInverse(factorial[k])) % modulo * modInverse(factorial[n - k])) % modulo;
}

int main() {
    factorial[0] = 1;
    for(int i = 1;i < N;i++)
        factorial[i] = (factorial[i - 1] * i) % modulo;
}
```

# Stars and bars:
The number of ways to put n (stars) identical objects into k (bars) labeled boxes is (n + k - 1)C(n)
