# Dijkstra's algorithm

## Dijkstra for dense graphs O(n^2)

```cpp
const int N = 2e2+5, M = 2e4, OO = 0x3f3f3f3f;

int n; // number of nodes

int adj[N][N]; //adjacency matrix

int dist[N], nVis[N];

void dijkstra(int src){
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    iota(nVis, nVis+n, 0);
    int nxt = src, s = n;
    while(nxt != -1){
        int u = nVis[nxt];      //Minimum Node
        nVis[nxt] = nVis[--s];
        nxt = -1;
        int mn = OO;
        for(int k = 0 ; k < s ; ++k){
            int v = nVis[k];
            int d = dist[u] + adj[u][v];
            if(dist[v] > d)         //Relax
                dist[v] = d;
            if(mn > dist[v]){
                mn = dist[v];
                nxt = k;
            }
        }
    }
}


int main(){
  memset(adj, OO, sizeof adj);
  //handle multiple edges if exists by taking the minimum
}

```


## Dijkstra for sparse graphs O((n + m) * log n) = O(m log n)

```cpp
const int N = 2e2+5, M = 2e4, OO = 0x3f3f3f3f;

int n; // number of nodes

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

void dijkstraSparse(int src){
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != dist[u])    continue;
        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            int dd = d + cost[e];
            if(dist[v] > dd){
                dist[v] = dd;
                q.push({-dd, v});
            }
        }
    }
}

int main(){
  // call init() after reading n;
}
```
