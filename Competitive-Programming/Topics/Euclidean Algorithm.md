# Euclidean Algorithm

The Euclidean Algorithm states that `gcd(a, b) = gcd(b, a % b)`, where `a` and `b` are two integers and `gcd(a, b)` is the greatest common divisor of `a` and `b`.

---

## Proof

- We can express `a` as `a = b * t + r` where `t` is the quotient and `r` is the remainder of `a/b` (`t = floor(a/b), r = a % b`).

**Let** `gcd(a, b) = d`

- That implies that `d | (b * t + r)` and since `d = gcd(a, b)` we know that `d | b`, hence `d | b * t` (`d` is a divisor of `b * t + r`, and `d` is divisor of `b`. if `d` is divisor of `b`, then `d` must be a divisor of `b * t`).

- So in order for `b * t + r` to be divisible by `d`, `r` must be divisible by `d`. We can deduce that `d | r`.

- Since `gcd(a, b) = d` then `d` is a divisor of `a` and `b`, and we just deduced that `d | r` then `d` must be a divisor of `gcd(b, r)`.

  ⇒ `gcd(a, b) | gcd(b, r)` **→ (1)**.

**Let** `c = gcd(b, r)`.

- if `c = gcd(b, r)` then `c | b` and `c | r` (`c` must be a divisor of `b` and a divisor of `r`).

- by definition `a = b * t + r`, then `c | a` (`c` must be a divisor of `a`).

- if `c | a`, `c | b`, and `c | r` then `c` must be a divisor of `gcd(a, b)`.

  ⇒ `gcd(b, r) | gcd(a, b)` **→ (2)**.


**from (1) and (2)** ⇒ `gcd(a, b) = gcd(b, r)`.

---

## GCD (recurive)
```CPP
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```

## GCD (iterative)
```CPP
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
```

### Time complexity `O(log(min(a, b)))`
