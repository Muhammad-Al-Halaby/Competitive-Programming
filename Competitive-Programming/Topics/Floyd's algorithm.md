# Floyd's algorithm

## Notes
1. You can choose the order of the added nodes to the graph (outer loop).
1. You can take advantage of this to check if some node belongs to some shortest path.

```cpp
const int N = 128, M = 2e5+5, OO = 0x3f3f3f3f;

int n; // number of nodes

int dist[N][N];

void floyd(){
    for(int k = 0 ; k < n ; ++k)
        for(int u = 0 ; u < n ; ++u)
            for(int v = 0 ; v < n ; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k]+dist[k][v]);
}

int main(){
  memset(dist, OO, sizeof dist);
  //handle multiple edges if exists by taking the minimum
}
```
