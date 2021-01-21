

# Get the MMI of just one number
```cpp
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
```

# Finding the modular inverse for every number modulo m

```cpp
inv[1] = 1;
for (int i = 2;i < m;i++)
	inv[i] = (m - (m/i) * inv[m%i] % m) % m;
```
# Finding the Modular Inverse using Extended Euclidean algorithm

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
# Finding the Modular Inverse using Binary Exponentiation
```cpp
power(a, p - 2) % p;
```


# Finding the Modular Inverse using Smallest Prime Factor
```cpp
inv[1] = 1;
for (int i = 2;i < m;i++)
	inv[x]=(inv[x/smallestPrimeFactor[x]]*inv[smallestPrimeFactor[x]])%m;
```
