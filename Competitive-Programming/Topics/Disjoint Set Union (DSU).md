# Disjoint Set Union (DSU)

# Code
```cpp
struct DSU{
    int parent[N], sz[N];
    int components, mxcomponent;

    void init(int n){
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
        components = n;
        mxcomponent = 1;
    }

    int find(int u){
        return (parent[u] == u) ? u : parent[u] = find(parent[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v)  return;

        if(sz[u] > sz[v])   swap(u ,v);

        parent[u] = v;
        sz[v] += sz[u];

        components--;
        mxcomponent = max(mxcomponent, sz[v]);
    }


    bool isInSameGroup(int u, int v){
        return find(u) == find(v);
    }

    int getSize(int u){
        return sz[find(u)];
    }
} dsu;
```

# Tutorials

[Disjoint Set Union (CP-Algorithms)](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
