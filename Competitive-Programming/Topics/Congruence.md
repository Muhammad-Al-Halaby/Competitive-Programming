# Congruence

#### `a ≡ b mod n` (`a` is congruent to `b` mod `n`)

#### Some properties of congruences

Suppose `a ≡ b mod n`, `c ≡ d mod n`

1. `a ± c ≡ b ± d mod n`.
1. `x * a ≡ x * b mod n`, where `x` is an integer.
1. `a * c ≡ (b * d) mod n`.
1. `a^n ≡ b^n mod n`, which is an extension to rule number `3` if `a` and `c` are equal.
1. if `x * a ≡ (x * y) mod n` and `n ∤ x`, then `a ≡ y mod n`, where `x` and `y` are integers (Cancellation Law).

**An important implication of these properties is that, when doing calculations `mod n` you can replace any number by another to which it is congruent, and nothing changes.**

**Fact: `a ≡ b mod n` iif `n | (a - b)`.**

##### Proof:
Step 1:  Assume `a ≡ b mod n` and prove `n` divides `a-b`.

Since `a ≡ b mod n`, we can write `a = q1 n + r` and `b = q2 n + r`.

Then `a-b = (q1-q2)n` is divisible by `n`.

Step 2:  Assume `n` divides `a-b` and prove `a ≡ b mod n`.

We know we can write `a = q1 n + r1` and `b = q2 n + r2`, with remainders `r1` and `r2` both between `0` and `n - 1`.

Then `a-b = (q1 - q2) n + (r1 - r2)`.

Because `n` goes evenly into `(q1 - q2) n`, the remainder when `a-b` is divided by `n` is the same as the remainder when `r1 - r2` is divided by `n`.

Since `a-b` is divisible by `n`, the remainder when `r1 - r2` is divided by `n` must be `0`.  So `r1 - r2` is a multiple of `n`.

But `r1` and `r2` are both numbers between `0` and `n - 1`, so the only way `r1 - r2` can be an even multiple of `n` is for it to equal `0`.

So `r1 = r2` and `a ≡ b mod n`.

#### Resources:
* https://www.youtube.com/watch?v=QgPfagOgOAc
* http://mathworld.wolfram.com/Congruence.html
