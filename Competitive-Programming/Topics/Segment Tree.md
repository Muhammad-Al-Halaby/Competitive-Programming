# Segment Tree

## Segment Tree with lazy propagation (simple)

```cpp
#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n;

ll t[4 * N], lazy[4 * N], a[N];

void check(int v, int l, int r){
    if(lazy[v]){
        t[v] += (r - l + 1) * lazy[v];
        if(l != r){
            lazy[v * 2 + 1] += lazy[v];
            lazy[v * 2 + 2] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void build(int v, int l = 0, int r = n - 1){
    check(v, l, r);

    if(l == r)
        return t[v] = a[l], void();

    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

void update(int v, int start, int end, ll val, int l = 0, int r = n - 1){
    check(v, l, r);

    if(start <= l && end >= r){
        t[v] += (r - l + 1) * val;
        if(l != r){
            lazy[v * 2 + 1] += val;
            lazy[v * 2 + 2] += val;
        }
        return;
    }

    if(start > r || end < l)  return;

    int mid = (l + r) / 2;
    update(2 * v + 1, start, end, val, l, mid);
    update(2 * v + 2, start, end, val, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

ll query(int v, int start, int end, int l = 0, int r = n - 1){
    check(v, l, r);

    //  return proper value
    if(start > r || end < l)  return 0;

    if(l >= start && r <= end)
        return t[v];

    int mid = (l + r) / 2;
    ll v1 = query(v * 2 + 1, start, end, l, mid);
    ll v2 = query(v * 2 + 2, start, end, mid + 1, r);

    // sum
    return v1 + v2;
}

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;
        memset(::t, 0, sizeof ::t);
        memset(lazy, 0, sizeof lazy);
        int q;  cin >> q;
        while(q--){
            int c, l, r, val; cin >> c >> l >> r; l--, --r;
            if(c == 0){
                cin >> val;
                update(1, l, r, val);
            }
            else cout << query(1, l, r) << '\n';
        }
    }
}
```

## Segment Tree with lazy propagation (more generic but painful to code)

```cpp
#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, a[N];

struct node{
    ll value, lazyValue;
    bool isLazy;

    node(){
        value = isLazy = 0;
    }

    node(ll val, ll lazyVal = 0, bool dirty = 0){
        value = val;
        lazyValue = lazyVal;
        isLazy = dirty;
    }

};

node emptyNode(0);

node t[4 * N];

void pushDown(int v, ll l, ll r){
    node &root = t[v];
    if(root.isLazy) {
        root.value += root.lazyValue * (r - l + 1);

        node &left = t[2 * v + 1];
        left.isLazy = 1;
        left.lazyValue += root.lazyValue;

        node &right = t[2 * v + 2];
        right.isLazy = 1;
        right.lazyValue += root.lazyValue;

        root.lazyValue = root.isLazy = 0;
    }
}

void build(int v, ll l, ll r){
    if(l == r)
        return t[v] = node(a[l]), void();

    int mid = l + (r - 0ll - l) / 2;

    build(v * 2 + 1, l, mid);
    build(v * 2 + 2, mid + 1, r);

    node &left = t[2 * v + 1];
    node &right = t[2 * v + 2];

    t[v] = node(left.value + right.value);
}

node query(int v, int start, int end, int l = 0, int r = n - 1) {
    pushDown(v, l, r);

    if(end < l || start > r)
        return emptyNode;

    if(start <= l && end >= r)
        return t[v];

    int mid = (l + r) / 2;

    node left = query(2 * v + 1, start, end, l, mid);
    node right = query(2 * v + 2, start, end, mid + 1, r);

    return node(left.value + right.value);
}

void update(int v, int start, int end, ll value, int l = 0, int r = n - 1){
    pushDown(v, l, r);

    if(end < l || start > r)
        return;

    if(start <= l && end >= r){
        t[v].isLazy = 1;
        t[v].lazyValue = value;
        pushDown(v, l, r);
        return;
    }

    int mid = l + (r - 0ll - l) / 2;
    update(v * 2 + 1, start, end, value, l, mid);
    update(v * 2 + 2, start, end, value, mid + 1, r);

    node &left = t[2 * v + 1];
    node &right = t[2 * v + 2];

    t[v] = node(left.value + right.value);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int q;
        cin >> q;

        for (int i = 0; i < n; i++) cin >> a[i];

        build(0, 0, n - 1);

        while (q--) {
            int type, l, r, v;
            cin >> type >> l >> r;
            l--, r--;
            if (type)
                cout << query(0, l, r).value << '\n';
            else {
                cin >> v;
                update(0, l, r, v); // range sum update
            }
        }
    }
}
```

## Problems
1. [KQUERY2 - K-query II (SPOJ)](https://www.spoj.com/problems/KQUERY2/)

# Tutorials:
1. [Persistent segment trees – Explained with spoj problems](https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/)
