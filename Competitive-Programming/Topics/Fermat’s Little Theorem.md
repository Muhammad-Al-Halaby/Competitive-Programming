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
