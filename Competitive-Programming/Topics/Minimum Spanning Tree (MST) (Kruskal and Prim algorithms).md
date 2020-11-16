# Minimum Spanning Tree (MST)

## Prim

### Prim for dense graphs O(n ^ 2)

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5, M = 2e4, OO = 0x3f3f3f3f;

int adj[N][N];
int t, n, m, u, v, c;

int dist[N], nVis[N];
int prim(int src){
    int res = 0;
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    iota(nVis, nVis+n, 0);
    int nxt = src, s = n;
    while(nxt != -1){
        int u = nVis[nxt];      //Minimum Node
        res += dist[u];
        nVis[nxt] = nVis[--s];
        nxt = -1;
        int mn = OO;
        for(int k = 0 ; k < s ; ++k){
            int v = nVis[k];
            int d = /*dist[u] +*/ adj[u][v];
            if(dist[v] > d)         //Relax
                dist[v] = d;
            if(mn > dist[v]){
                mn = dist[v];
                nxt = k;
            }
        }
    }
    return res;
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        memset(adj, OO, sizeof adj);
        int total = 0;
        while(m--){
            scanf("%d %d %d", &u, &v, &c);
            adj[u][v] = min(adj[u][v], c);
            adj[v][u] = min(adj[v][u], c);
            total += c;
        }
        printf("%d\n", total - prim(0));
    }
    return 0;
}
```

### Prim for sparse graphs O((n + m) log n) = O(m log n)

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5, M = 2e4, OO = 0x3f3f3f3f;

int t, n, m, u, v, c;

int ne, head[N], nxt[M], to[M], cost[M];

void init(){
    memset(head, -1, n*sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}

int dist[N];
int vis[N], vid;
int primSparse(int src){
    memset(dist, OO, sizeof dist);
    int res = 0;
    dist[src] = 0;
    ++vid;
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();
        if(vis[u] == vid)    continue;
        res += d;
        vis[u] = vid;
        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            if(vis[v] == vid)   continue;
            int dd = /*d +*/ cost[e];
            if(dist[v] > dd){
                dist[v] = dd;
                q.push({-dd, v});
            }
        }
    }
    return res;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        int total = 0;
        init();
        while(m--){
            scanf("%d %d %d", &u, &v, &c);
            addBiEdge(u, v, c);
            total += c;
        }
        printf("%d\n", total - primSparse(0));
    }
    return 0;
}
```


## Kruskal

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5, M = 1e6+6, OO = 0x3f3f3f3f;

int n, parent[N], sz[N], comps, mxComp;

void init(){
    iota(parent, parent+n, 0);
    fill(sz, sz+n, 1);
    comps = n;
    mxComp = 1;
}

int find(int u){
    return u == parent[u] ? u : parent[u] = find(parent[u]);
}

bool join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)  return 0;
    if(sz[u] > sz[v])   swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];
    --comps;
    mxComp = max(mxComp, sz[v]);
    return 1;
}

int from[M], to[M], cost[M], sorted[M];

int t, m, u, v, c, total;


int kruskal(){
    init();
    sort(sorted, sorted+m, [](int a, int b){
        return cost[a] < cost[b];
    });
    int res = 0;
    for(int k = 0 ; k < m && comps > 1; ++k){
        int e = sorted[k];
        if(join(from[e], to[e]))    res += cost[e];
    }
    return res;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        total = 0;
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &u, &v, &c);
            from[i] = u;
            to[i] = v;
            cost[i] = c;
            sorted[i] = i;
            total += c;
        }
        printf("%d\n", total - kruskal());
    }
    return 0;
}
```
