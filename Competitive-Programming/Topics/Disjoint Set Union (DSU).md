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


# DSU on Tree (Sack):
It optimises for calculation of some property for a subtree by maintaining the answer for it’s heaviest child’s subtree (child with the largest subtree size) and iterating on rest of the subtree nodes to complete the calculation for the current node.
https://codeforces.com/blog/entry/44351

DSU on Tree (Small to Large)
https://codeforces.com/blog/entry/67696

https://codeforces.com/contest/600/problem/E
