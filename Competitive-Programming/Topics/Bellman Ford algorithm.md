# Bellman Ford algorithm


## Bellman without optimizations O(n * m)

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+1, M = 3e3+2, OO = 0x3f3f3f3f;

struct e{
    int f, t, c;
}edges[M];

int t, n, m, u, v, c;

int dist[N];

bool bellman(int src){
    memset(dist, OO, n*sizeof dist[0]);
    dist[src] = 0;
    int x = n;
    while(x--){
        for(int i = 0 ; i < m ; ++i){
            e& edge = edges[i];
            int d = dist[edge.f] + edge.c;
            if(dist[edge.t] > d){
                dist[edge.t] = d;
                if(!x)  return 0;
            }
        }
    }
    return 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &u, &v, &c);
            edges[i] = {u, v, c};
        }
        for(int i = 0 ; i < n ; ++i){
            edges[m++] = {n, i, 0};
        }
        puts(bellman(n++) ? "not possible" : "possible");
    }

    return 0;
}
```



## Bellman with optimizations (better than O(n * m))

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+1, M = 3e3+2, OO = 0x3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], cost[M];

void init(){
    memset(head, -1, n*sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}


int dist[N];
int inQ[N], vid;
bool bellman(int src){
    memset(dist, OO, n*sizeof dist[0]);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQ[src] = ++vid;
    int x = n;
    int s;
    while(x-- && (s = q.size())){
        while(s--){
            int u = q.front();
            q.pop();
            inQ[u] = 0;
            for(int e = head[u] ; ~e ; e = nxt[e]){
                int v = to[e];
                int d = dist[u] + cost[e];
                if(dist[v] > d){
                    dist[v] = d;
                    if(inQ[v] != vid){
                        q.push(v);
                        inQ[v] = vid;
                    }
                    if(!x)  return 0;
                }
            }
        }
    }
    return 1;
}

int t, m, u, v, c;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        ++n;
        init();
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &u, &v, &c);
            addEdge(u, v, c);
        }
        for(int i = 0 ; i < n-1 ; ++i){
            addEdge(n-1, i, 0);
        }
        puts(bellman(n-1) ? "not possible" : "possible");
    }

    return 0;
}
```
