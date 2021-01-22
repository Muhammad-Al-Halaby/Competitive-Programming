# SQRT Decomposition

- split updates into buckets (apply permanent updates at the start of each bucket, otherwise use a slow query)
- split input numbers into buckets (on certain property like min, mx, sum, freq, etc).

- Note: sqrt(1e5) = 316, sqrt(1e6) = 1e3

Problem: Given two types of queries on an array:
1. update element at index i to val
1. count the numbers less than x in range [l, r]

```cpp
#include <bits/stdc++.h>

using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;


int n, q, a[N], sorted[N], root;

int main(){
    init();

    cin >> n >> q;

    root = sqrt(n);

    for(int i = 0;i < n;i++)    cin >> a[i], sorted[i] = a[i];
    for(int i = 0;i < n;i += root){
        sort(sorted + i, sorted + min(n, i + root));
    }

    for(int i = 0;i < q;i++){
        char t; cin >> t;
        if(t == 'M'){
            int idx, val;   cin >> idx >> val;  idx--;

            a[idx] = val;

            int bucketNum = idx / root;
            int f = bucketNum * root;
            for(int j = f;j < n && j < f + root;j++){
                sorted[j] = a[j];
            }

            sort(sorted + f, sorted + f + root);

            continue;
        }

        int l, r, k;    cin >> l >> r >> k; l--, r--;

        int ans = 0;
        for(int j = l;j <= r;j++){
            if(j % root == 0 && j + root - 1 <= r){
                int idx = upper_bound(sorted + j, sorted + j + root, k) - sorted;
                ans += idx - j;
                j += root - 1;
            }
            else ans += (a[j] <= k);
        }

        cout << ans << '\n';
    }

}
```


## Problems
1. [RMQSQ - Range Minimum Query (SPOJ)](https://www.spoj.com/problems/RMQSQ/)
1. [KQUERY - K-query (SPOJ)](https://www.spoj.com/problems/KQUERY/)
1. [RACETIME - Race Against Time (SPOJ)](https://www.spoj.com/problems/RACETIME/)
1. [Intro to SQRT-Decomposition Contest - ACM JCPC Training](https://codeforces.com/group/BDIXyZZHhT/contest/205512)
1. [Pair of Topics - CF-Div3-D](https://codeforces.com/contest/1324/problem/D)
1. [Xenia and Tree CF-Div2-E](https://codeforces.com/contest/342/problem/E)
1. [Holes - CF-Div2-E](https://codeforces.com/contest/13/problem/E)
1. Extendable Sorted Array - (2 Queries: 1: add a to array, 2: print count of numbers [l, r]) -> (segment tree on frequencies (offline)), (sqrt decomp with sorting buckets and merge like merge sort and answering queries with binary search), (numbers compression and split frequencies of values into sqrt buckets and update frequencies).
1. [New Year Tree - CF-Div2-E](https://codeforces.com/contest/620/problem/E) (SQRT-Decomposition with lazy propagation)


1. You have N different nodes in a graph and is responsible for 3 queries:

1) Connect 2 nodes by an edge 2) Delete edge between 2 nodes 3) Query whether or not 2 nodes are connected.

You can break the queries into O(sqrt(N)) chunks and process each individually using Union Find.

# Not Solved Yet
1. https://codeforces.com/contest/1199/problem/D
1. https://codeforces.com/contest/622/problem/C
1. https://codeforces.com/problemset/problem/551/E
1. https://codeforces.com/contest/455/problem/D
1. https://codeforces.com/contest/513/problem/F2
1. https://www.codechef.com/problems/CHEFEXQ
1. https://www.codechef.com/problems/FNCS
1. https://codeforces.com/contest/86/problem/D
1. https://www.hackerearth.com/problem/algorithm/final-question/description/
1. https://www.codechef.com/OCT16/problems/BGQRS

# Tutorials:
- SolverToBe
- https://cp-algorithms.com/data_structures/sqrt_decomposition.html
- http://acm.math.spbu.ru/~sk1/mm/lections/mipt2016-sqrt/mipt-2016-burunduk1-sqrt.en.pdf
- https://www.infoarena.ro/blog/square-root-trick
- http://ayurjain.blogspot.com/2016/08/square-root-decomposition.html?view=sidebar
- https://assets.hkoi.org/training2019/sqrt.pdf
