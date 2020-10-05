# Lowest Common Ancestor


## LCA using Sparse Table:

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}


const int mxDepth = 20;
int depth[N], dp[N][mxDepth + 9];

void dfsLCA(int u, int p){
    dp[u][0] = p;
    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];
        if(v == p)  continue;
        depth[v] = depth[u] + 1;
        dfsLCA(v, u);
    }
}

void buildSparseTable(){
    memset(dp, -1, sizeof dp);

    dfsLCA(0, -1);

    for(int k = 1;k <= mxDepth;k++){
        for(int u = 0;u < n;u++){
            int v = dp[u][k - 1];
            if(v == -1)  continue;
            // 2^k = 2^(k - 1) + 2^(k - 1)
            dp[u][k] = dp[v][k - 1];
        }
    }
}

int getKthAncestor(int u, int k){
    if(k == 0)  return u;

    int d = depth[u] - k;

    for(int i = mxDepth;i >= 0;i--){
        int v = dp[u][i];
        if(v == -1) continue;
        if(depth[v] == d)   return v;
        else if(depth[v] > d)   u = v;
    }

    return -1;
}

int getLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    u = getKthAncestor(u, depth[u] - depth[v]);

    if(u == v)  return u;

    for(int i = mxDepth;i >= 0;i--){
        int nu = dp[u][i];
        int nv = dp[v][i];
        if(nu != nv){
            u = nu;
            v = nv;
        }
    }

    return dp[u][0];
}

int u, v;

int main(){
    init();

    cin >> n;

    initGraph();

    for(int i = 0;i < n - 1;i++){
        cin >> u >> v;  u--, v--;
        addBiEdge(u, v);
    }

    buildSparseTable();

    // returns -1 if there is no k-th ancestor to u
    cout << getKthAncestor(u, k) + 1 << '\n';

    cout << getLCA(u, v) + 1 << '\n';
}
```

## Implementation with Weighted Edges:

```cpp
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], cost[M];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}

const int mxDepth = 20;
int depth[N];

pii dp[N][mxDepth + 9];

void dfsLCA(int u, int p){
    dp[u][0].F = p;
    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];
        int c = cost[k];

        if(v == p)  continue;
        depth[v] = depth[u] + 1;
        dp[v][0].S = c;
        dfsLCA(v, u);
    }
}

void buildSparseTable(){
    memset(dp, -1, sizeof dp);

    dfsLCA(0, -1);

    for(int k = 1;k <= mxDepth;k++){
        for(int u = 0;u < n;u++){
            int v = dp[u][k - 1].F;
            int c = dp[u][k - 1].S;
            if(v == -1)  continue;
            // 2^k = 2^(k - 1) + 2^(k - 1)
            dp[u][k].F = dp[v][k - 1].F;
            dp[u][k].S = c + dp[v][k - 1].S;
        }
    }
}

pii getKthAncestor(int u, int k){
    if(k == 0)  return {u, 0};

    int d = depth[u] - k;

    int dist = 0;
    for(int i = mxDepth;i >= 0;i--){
        int v = dp[u][i].F;
        int c = dp[u][i].S;

        if(v == -1) continue;
        if(depth[v] >= d){
            u = v;
            dist += c;
        }
    }

    return {u, dist};
}


pii calcDist(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    pii p = getKthAncestor(u, depth[u] - depth[v]);

    u = p.F;

    int dist = p.S;

    if(u == v)  return {u, dist};

    for(int i = mxDepth;i >= 0;i--){
        int nu = dp[u][i].F, cu = dp[u][i].S;
        int nv = dp[v][i].F, cv = dp[v][i].S;
        if(nu != nv){
            dist += cu + cv;
            u = nu;
            v = nv;
        }
    }

    dist += dp[u][0].S + dp[v][0].S;

    return {dp[u][0].F, dist};
}


int kthNode(int u, int v, int k){
    pii p = calcDist(u, v);
    int lca = p.F, du = depth[u] - depth[lca];
    if(du >= k)
        return getKthAncestor(u, k).F;

    int dv = depth[v] - depth[lca];
    return getKthAncestor(v, dv - (k - du)).F;
}

int m, u, v, c, k;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;
        initGraph();
        for(int i = 0;i < n - 1;i++){
            cin >> u >> v >> c;  u--, v--;
            addBiEdge(u, v, c);
        }

        buildSparseTable();

        string q;
        while(cin >> q && q != "DONE"){
            if(q == "DIST"){
                cin >> u >> v;  u--, v--;
                cout << calcDist(u, v).S << '\n';
            }
            else{
                cin >> u >> v >> k; u--, v--, k--;
                cout << kthNode(u, v, k) + 1 << '\n';
            }
        }
    }
}
```

## Problems

1. [LCA - Lowest Common Ancestor (SPOJ)](https://www.spoj.com/problems/LCA)
1. [Xenia and Tree CF-Div2-E](https://codeforces.com/contest/342/problem/E)
1. [QTREE2 - Query on a tree II (SPOJ)](https://www.spoj.com/problems/QTREE2/)
