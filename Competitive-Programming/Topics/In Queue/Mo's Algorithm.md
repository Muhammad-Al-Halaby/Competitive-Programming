# Mo's algorithm

```cpp
#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;
//a[i + 1] = a[i];

int n, q, a[N], sqroot;

struct query {
    int l, r, q_idx, block_idx;

    query() {}
    query(int _l, int _r, int _q_idx) {
        l = _l - 1, r = _r - 1, q_idx = _q_idx, block_idx = _l / sqroot;
    }
    bool operator <(const query &y) const {
        if (block_idx != y.block_idx)
            return block_idx < y.block_idx;
        return r < y.r;
    }
};


int freq[N];

int result = 0;
int q_ans[N];
query queries[N];

void add(int idx) {
    freq[a[idx]]++;
    if (freq[a[idx]] == 3)
        result++;
}

void remove(int idx) {
    freq[a[idx]]--;
    if (freq[a[idx]] == 2)
        result--;
}

void process() {  // don't change
    sort(queries, queries + q);

    int curL = 1, curR = 0; // tricky initialization and indexing
    for (int i = 0; i < q; i++) {
        while (curL < queries[i].l) remove(curL++);
        while (curL > queries[i].l) add(--curL);
        while (curR < queries[i].r) add(++curR);
        while (curR > queries[i].r) remove(curR--);
        q_ans[queries[i].q_idx] = result;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;

    sqroot = sqrt(q);

    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < q;i++){
        int l, r;   cin >> l >> r;
        queries[i] = query(l, r, i);
    }

    process();

    for (int i = 0; i < q; i++)
        cout << q_ans[i] << '\n';
}
```


# Problems
1. https://www.spoj.com/problems/DQUERY/
1. https://codeforces.com/problemset/problem/86/D
1. https://www.spoj.com/problems/COT2/
1. https://www.codechef.com/MARCH14/problems/GERALD07
1. https://codeforces.com/problemset/problem/375/D
1. https://www.codechef.com/problems/GERALD3
1. https://codeforces.com/problemset/problem/351/D
1. https://www.codechef.com/problems/IITI15
1. https://www.codechef.com/problems/CLOSEFAR
1. https://codeforces.com/contest/617/problem/E
1. https://www.spoj.com/problems/ZQUERY/
1. https://www.hackerearth.com/challenges/competitive/july-clash-15/algorithm/something-genuine/
1. https://www.spoj.com/problems/FREQUENT/
1. https://www.hackerrank.com/contests/w12/challenges/white-falcon-and-tree (https://www.hackerrank.com/contests/w12/challenges/white-falcon-and-tree/submissions/code/2445084)



# Tutorials
- SolverToBe
- https://assets.hkoi.org/training2019/sqrt.pdf
- https://codeforces.com/blog/entry/43230
- https://blog.anudeep2011.com/mos-algorithm/
