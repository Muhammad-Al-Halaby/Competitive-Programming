# Euler Tour

## Eulerian Graphs

#### Definition: A graph G=(V(G),E(G)) is considered Eulerian if the graph is both connected and has a closed trail (a walk with no repeated edges) containing all edges of the graph.

#### Definition: An Eulerian Trail is a closed walk with no repeated edges but contains all edges of a graph G=(V(G),E(G)) and return to the start vertex. A graph with an Eulerian trail is considered Eulerian.

#### A graph G=(V(G),E(G)) is Eulerian if and only if each vertex has an even degree.

#### Essentially, a graph is considered Eulerian if you can start at a vertex, traverse through every edge only once, and return to the same vertex you started at.

#### Euler Cycle in undirected graphs: All nodes must have even degrees.

#### Euler Cycle in directed graphs: in-degree = out-degree for all nodes.

#### Things to handle: multiple edges, self loops, disconnected graphs.
---

## Semi-Eulerian Graphs

#### Definition: A graph G=(V(G),E(G)) is considered Semi-Eulerian if it is connected and there exists an open trail containing every edge of the graph (exactly once as per the definition of a trail). You do not need to return to the start vertex.

#### Definition: A Semi-Eulerian trail is a trail containing every edge in a graph exactly once. A graph with a semi-Eulerian trail is considered semi-Eulerian.

#### Essentially the bridge problem can be adapted to ask if a trail exists in which you can use each bridge exactly once and it doesn't matter if you end up on the same island. Unfortunately, there is once again, no solution to this problem.

#### A graph is semi-Eulerian if and only if there is one pair of vertices with odd degree.

#### Euler path in undirected graphs: Start/End nodes must have odd degrees, others even degrees.

#### Euler path in directed graphs:
  - start = in-degree = out-degree - 1
  - end = in-degree = out-degree + 1
  - others = in-degree = out-degree

## Code that prints Euler path from start node to end node
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 5e2+5, M = 3e3+5, OO = 0x3f3f3f3f;

int m, u, v;
int ne, head[N], nxt[M], to[M], IN[N];

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    IN[t] ^= 1;
    head[f] = ne++;
}

void addBiEdge(int a, int b){
    addEdge(a, b);
    addEdge(b, a);
}

pair<int, int> E[M];
int mn;
int vis[M], vid;
vector<int> ans;

void eulerDFS(int u){
    for(int& k = head[u] ; ~k ; ){
        int v = to[k];
        int e = k;
        k = nxt[k];         //delete this "Forward" Edge
        if(vis[e] == vid)   continue;
        vis[e^1] = vid;
        eulerDFS(v);
    }
    ans.push_back(u);
}

int main(){
    // freopen("fence.in", "rt", stdin);
    // freopen("fence.out", "wt", stdout);
    scanf("%d", &m);
    init();
    for(int i = 0 ; i < m ; ++i){
        scanf("%d %d", &u, &v);
        --u, --v;
        mn = min(mn, min(u, v));
        E[i] = {min(u, v), max(u, v)};
    }
    sort(E, E+m);
    while(m--)  addBiEdge(E[m].first, E[m].second);
    int x = find(IN, IN+N, 1)-IN;
    if(x != N)  mn = x;
    ++vid;
    eulerDFS(mn);
    for(int i = int(ans.size())-1 ; ~i ; --i){
        printf("%d\n", ans[i]+1);
    }
    return 0;
}
```
