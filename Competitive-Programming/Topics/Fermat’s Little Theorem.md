# Fermat’s Little Theorem
**The theorem states that `a^(p-1) ≡ 1 mod p` if `a` is an integer, `p` is a prime number and `a` and `p` are coprime (`p ∤ a`).**

Another form is `a^p ≡ a mod p`. The restated form is nice because we no longer need to restrict ourselves to integers `a` not divisible by `p`.

In contest problems, Fermat's Little Theorem is often used in conjunction with the Chinese Remainder Theorem to simplify tedious calculations.

### Proof

`a` must be congruent to some number in the set `S = {1, 2, 3, ..., p-1}` (`0` is not included cause `p ∤ a`).

If we multiply `a * S`, we get `{a, 2*a, 3*a, ..., (p-1)*a}`

if we take this set `mod p` we get a permutation of the original set `{1, 2, ..., p-1}`, but let's prove that!

###### Case 1: none of these numbers are congruent to zero.

Suppose `r * a ≡ 0 mod p`, that means `p | (r * a)` and we know that `p ∤ a` and `p` can't divide `r` because `r < p`.

###### Case 2: These are distinct. no two are congruent to each other.

Pick two values, `r * a`, `s * a`

We know that: `0 < r < p` and `0 < s < p`

Let's show that `r * a` is not congruent to `s * a mod p`

Let's look at `r * a - s * a = a * (r - s)`.

We know that `p ∤ a`, Can `p | (r - s)`? (because if `p | (r - s)` that would mean that `r ≡ s mod p`.

Since, `0 < r < p` and `-p < -s < 0`, we add the inequalities to get `-p < (r - s) < p`.

Now we know that `p` can't divide `r - s` because `(r - s) < p`, hence `r` is not congruent to `s mod p`, `r` and `s` are distinct, and `r * a` is not congruent to `s * a mod p`.


From case 1 and case 2, we conclude that the set is a permutation of the original set `S`.


The product of the elements in the set `a * S` are `a * 2*a * .... * (p-1)*a ≡ 1 * 2 * .... * (p-1) mod p` which is equal to `(p-1)! * a^(p-1) ≡ (p-1)! mod p`, and `p ∤ (p-1)!` so we can cancel it from both sides to get `a^(p-1) ≡ 1 mod p` and that proves Fermat's Little Theorem.

---

## Applications
### 1- Modular Multiplicative Inverse

Fermat's Little Theorem can be used to calculate the modular multiplicative inverse.

if `p` is prime, and `p ∤ a` then from Fermat's Little theorem `a^(p-1) ≡ 1 mod p`, we can factor `a` out to get `a * a^(p-2) ≡ 1 mod p`, from that we conclude that `a^(p-2)` is the modular multiplicative inverse of `a` for `mod p`.

```CPP
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mulmod(ll a,ll b,ll mod){
    ll x = 0,y=a%mod;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%mod;
        }
        y = (y*2)%mod;
        b /= 2;
    }
    return x%mod;
}

ll power(ll b, ll e, ll mod){
    if(e == 1)  return b;
    ll ans = power(b, e / 2, mod);
    ans = mulmod(ans, ans, mod);
    if(e & 1)   ans = mulmod(ans, b, mod);
    return ans;
}

//iif p is prime, gcd(a, p) == 1;
ll modular_mul_inv(ll a, ll p){
    return power(a, p - 2, p);
}

int main(){
    ll n, p;  cin >> n >> p;
    cout << modular_mul_inv(n, p);
}
```

### 2- Fermat's Primality Test

Fermat's Little Theorem can be used in primality testing.

For a number `p` to be prime, this relation must hold `a^(p - 1) ≡ 1 mod p` for every `a` that's relatively prime with `p` (`1 < a < p`).

This can also be used for calculating the number of divisors in `O(n^(1/3))`.

```CPP
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mulmod(ll a,ll b,ll mod){
    ll x = 0,y=a%mod;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%mod;
        }
        y = (y*2)%mod;
        b /= 2;
    }
    return x%mod;
}

ll power(ll b, ll e, ll mod){
    if(e == 1)  return b;
    ll ans = power(b, e / 2, mod);
    ans = mulmod(ans, ans, mod);
    if(e & 1)   ans = mulmod(ans, b, mod);
    return ans;
}

//Fermat's Primality Test in log(n)
bool is_prime(ll n, int k){
    if(n <= 1 || n == 4)    return false;
    if(n <= 3)  return true;

    bool x = true;
    while(k--){
        ll a = 2 + rand() % (n - 2);
        x &= __gcd(a, n) == 1;
        x &= power(a, n - 1, n) == 1;
        if(x == 0) cout << a << endl;
    }
    return x;
}

//Calculate number of divisors in O(n^(1/3))
ll number_of_divisors(ll n){
    ll ans = 1;
    //remove all factors less then n^(1/3)
    for(ll i = 2;i * i * i <= n;i++){
        if(n % i)   continue;
        ll c = 0;
        while(n % i == 0)
            n /= i, c++;
        ans *= (c + 1);
    }

    if(n == 1)  return ans;

    //n can have at most 2 more factors greater than n^(1e3),
    //n can either be prime, a square of a prime, or a product of two primes.
    ll sq = sqrtl(n);
    if(sq * sq == n)
        ans *= 3;
    else if(is_prime(n, 20))
        ans *= 2;
    else
        ans *= 4;

    return ans;
}

int main(){
    ll n;   cin >> n;
    cout << is_prime(n , 20) << '\n';
    cout << number_of_divisors(n);
}
```
* **Note:** Fermat's primality test could fail with Carmichael numbers (such as: `561`).

#### Problems
* https://codeforces.com/gym/100753/problem/F
* https://www.spoj.com/problems/PON/
*  https://www.spoj.com/problems/SAS002/
* https://www.spoj.com/problems/NUMDIV/

#### Resources:
* https://www.youtube.com/watch?v=w0ZQvZLx2KA
* https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/
