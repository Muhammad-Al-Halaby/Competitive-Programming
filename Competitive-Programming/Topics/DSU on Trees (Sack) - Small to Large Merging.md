# DSU on Trees (Sack) / Small to Large Merging

A way to merge two sets efficiently.


It optimises calculation of some property for a subtree by maintaining the answer for it’s heaviest child’s subtree (child with the largest subtree size) and iterating on rest of the subtree nodes to complete the calculation for the current node.

Let's consider a tree rooted at node `1`, where each node has a color.

For each node, let's store a set containing only that node, and we want to merge the sets in the nodes subtree together such that each node has a set consisting of all colors in the nodes subtree. Doing this allows us to solve a variety of problems, such as query the number of distinct colors in each subtree.

Instead of

```CPP
for (int x : b) a.insert(x);
```

which runs in `O(mlog(n+m))` time, yielding a runtime of
`O(N^2logN)` in the worst case. If we instead maintain `a` and `b`
as sorted vectors, we can merge them in `O(n+m)` time, but
`O(N^2)` is also too slow.

With just one additional line of code, we can significantly speed this up.
```CPP
if (a.size() < b.size()) swap(a, b);
for (int x : b) a.insert(x);
```

Note that [swap](http://www.cplusplus.com/reference/utility/swap/) exchanges two
sets in `O(1)` time. Thus, merging a smaller set of size `m` into the
larger one of size `n` takes `O(mlogn)` time.

**Claim:** The solution runs in `O(Nlog^2N)` time.

**Proof:** When merging two sets, you move from the smaller set to the larger
set. If the size of the smaller set is `X`, then the size of the resulting set
is at least `2X`. Thus, an element that has been moved `Y` times will be in a
set of size at least `2^Y`, and since the maximum size of a set is `N` (the
root), each element will be moved at most `O(logN`) times.


---

## Problem

You're a given tree of `N` nodes rooted at node `1`. Each node `i` `(1 <= i <= N)` contains a value `v_i`. You're required to answer `Q` queries of the form `(u,d)`: For each query, output the sum of values written on all nodes at distance not greater than `d` from `u` and lies inside `u`'s subtree.

```CPP
#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e6 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N];

vector<int> adj[N];
int height[N];
vector<pair<int, int>> queries[N];

ll ans[N];

struct Data {
    map<int, ll> sum;

    void add(int depth, ll x, bool merge = 1) {
        if (merge)
            sum[depth] += x;
        else
            sum[depth] = x + sum[depth + 1];

;

void dfs(int u, int p) {
    height[u] = 0;
    for (auto v: adj[u]) {
        if(v == p)  continue;
        dfs(v, u);
        height[u] = max(height[u], 1 + height[v]);



Data dfs(int u, int p, int depth) {
    Data ret;
    for (auto v: adj[u]) {
        if(v == p)  continue;
        Data child_ret = dfs(v, u, depth + 1);

        if (child_ret.sum.size() > ret.sum.size())
            swap(ret, child_ret);

        for (auto[d, sum]: child_ret.sum)
            ret.add(d, sum);


    ret.add(depth, a[u], 0);

    for (auto[i, d]: queries[u])
        ans[i] = ret.sum[depth] - (d + 1 > height[u] ? 0 : ret.sum[depth + d + 1]);

    return ret;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            adj[i].clear();
            queries[i].clear();


        for(int i = 0;i < n - 1;i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);


        dfs(0, 0);

        for (int i = 0; i < q; i++) {
            int u, d;
            cin >> u >> d;
            u--;
            queries[u].push_back({i, d);


        dfs(0, 0, 0);

        for (int i = 0; i < q; i++)
            cout << ans[i] << " \n"[i == q - 1];


```

# Tutorials

[[Tutorial] Sack (dsu on tree)](https://codeforces.com/blog/entry/44351)

[[Explanation] dsu on trees (small to large)](https://codeforces.com/blog/entry/67696)

[Small-To-Large Merging](https://usaco.guide/plat/merging?lang=cpp)

# Problems

https://codeforces.com/contest/600/problem/E

https://codeforces.com/contest/375/problem/D

https://codeforces.com/contest/1009/problem/F
