# Ternary Search


# Note
1. Some functions can be split into two convex/concave intervals.

## Code to find min value in a
```cpp
double l = 0, r = 2e9;
int cnt = 1000; //to avoid TLE
while (cnt && r - l > EPS) {
    double third = (r - l) / 3;
    double lf = l + third, rg = r - third;

    if (check(lf) < check(rg))r = rg;
    else l = lf;
    cnt--;
}
```
