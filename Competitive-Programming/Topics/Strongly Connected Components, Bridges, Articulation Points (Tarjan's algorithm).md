# Strongly Connected Components, Bridges, Articulation Points (Tarjan's algorithm)


## Code
```cpp
#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

#define F first
#define S second

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
    int n, ne, head[N], nxt[M], to[M], cost[M];

    void initGraph(int n) {
        memset(head, -1, n * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t, int c) {
        to[ne] = t;
        cost[ne] = c;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
};

int inTime[N], lowTime[N], dfsTime, inStack[N], art[N], compID[N], cmpID, vis[N], vid;

stack<int> stk;
vector<vector<int>> comps;
vector<pair<int, int>> bridges;

void dfs(int u, int p, Adj &adj){
    inTime[u] = lowTime[u] = ++dfsTime;
    inStack[u] = 1;
    stk.push(u);
    vis[u] = vid;
    neig(adj, u, e, v){
        if(v == p)  continue;

        if (vis[v] != vid)
            dfs(v, u, adj);
        else {
            lowTime[u] = min(lowTime[u], inTime[v]);
            continue;
        }

        if(inTime[u] < lowTime[v])
            bridges.push_back({u, e});

        if(inTime[u] <= lowTime[v])
            art[u] = (inTime[u] > 1 || inTime[v] > 2);

        lowTime[u] = min(lowTime[u], lowTime[v]);
    }

    if(inTime[u] == lowTime[u]){
        vector<int> component;
        while(true){
            int v = stk.top();
            stk.pop();
            inStack[v] = 0;
            compID[v] = cmpID;
            component.push_back(v);
            if(v == u)  break;
        }
        comps.push_back(component);
        cmpID++;
    }
}

void init(){
    vid++;
    dfsTime = 0;
    cmpID = 0;
    bridges.clear();
}

int n, m, u, v, c;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();

    cin >> n >> m;

    Adj graph;

    graph.initGraph(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        u--, v--;
        graph.addBiEdge(u, v, c);
    }

    for (int u = 0, t; u < n; ++u)
        if (vis[u] != vid)
            dfs(u, -1, graph);
}
```
