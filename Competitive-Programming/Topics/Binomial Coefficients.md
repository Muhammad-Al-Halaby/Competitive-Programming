# Binomial Coefficients

# Code for N choose K
```cpp
ll iterativeChoose(ll n, ll k){
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
