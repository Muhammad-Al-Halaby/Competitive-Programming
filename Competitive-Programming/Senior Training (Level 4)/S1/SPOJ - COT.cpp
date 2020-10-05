#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int head[N], nxt[M], to[M], weight[N], ne;

int n, q;

void initGraph(){
    memset(head, -1, (n + 1) * sizeof head[0]);
    ne = 0;
}

void addEdge(int u, int v){
    to[ne] = v;
    nxt[ne] = head[u];
    head[u] = ne++;
}

void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}

struct node;

extern node *empty;

struct node{
    ll freq;
    node *left, *right;

    node(){
        freq = 0;
        left = right = this;
    }

    node(node *l, node *r, int cnt){
        freq = cnt;
        left = l;
    }

};
right = r;

node *empty = new node;

node* insert(node *root, int &val, int l = INT_MIN, int r = INT_MAX){
    if(val < l || val > r)  return root;

    if(l == r)
        return new node(root->left, root->right, root->freq + 1);


    int mid = l + (r - 0ll - l) / 2;
    node *left = insert(root->left, val, l, mid);
    node *right = insert(root->right, val, mid + 1, r);

    return new node(left, right, left->freq + right->freq);
}

int query(node *u, node *v, node *lca, node *lcaParent, int k, int l = INT_MIN, int r = INT_MAX){
    if(l == r)
        return l;

    int mid = l + (r - 0ll - l) / 2;
    int left = u->left->freq + v->left->freq - lca->left->freq - lcaParent->left->freq;
    if(left >= k)
        return query(u->left, v->left, lca->left, lcaParent->left, k, l, mid);
    else
        return query(u->right, v->right, lca->right, lcaParent->right, k - left, mid + 1, r);
}

vector<int> node2index, index2node, depth;
vector<node*> roots, parents;

void initDFS(){
    depth.resize(n + 1);
    roots.resize(n + 1);
    parents.resize(n + 1);
    node2index.resize(n + 1);
}

void dfs(int u, int p = 0, int dpth = 0, node* parentRoot = empty){

    node2index[u] = index2node.size();
    index2node.push_back(u);

    depth[u] = dpth;

    parents[u] = parentRoot;
    roots[u] = insert(parentRoot, weight[u]);

    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == p)  continue;
        dfs(v, u, dpth + 1, roots[u]);
        index2node.push_back(u);
    }
}

int sparseTable[N][20], logs[N];

void buildSPT(){
    logs[0] = -1;
    for(int i = 0;i < index2node.size();i++) {
        logs[i + 1] = logs[i] + !(i & (i + 1));
        sparseTable[i][0] = i;
    }

    for(int j = 1;(1 << j) < index2node.size();j++){
        for(int i = 0;i + (1 << j) < index2node.size();i++){
            int a = sparseTable[i][j - 1];
            int b = sparseTable[i + (1 << (j - 1))][j - 1];
            sparseTable[i][j] = (depth[index2node[a]] < depth[index2node[b]] ? a : b);
        }
    }
}

int getRMQ(int l, int r){
    int d = r - l + 1;
    int log = logs[d];

    int a = sparseTable[l][log];
    int b = sparseTable[r - (1 << log) + 1][log];

    return (depth[index2node[a]] < depth[index2node[b]] ? a : b);
}

int getLCA(int u, int v) {
    int l = node2index[u];
    int r = node2index[v];

    if(l > r)   swap(l, r);

    return index2node[getRMQ(l, r)];
}

void go(int tc = 0){

    cin >> n >> q;

    initGraph();

    for(int i = 1;i <= n;i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        addBiEdge(u, v);
    }

    initDFS();
    dfs(1);

    buildSPT();

    while(q--){
        int u, v, k;    cin >> u >> v >> k;
        int lca = getLCA(u, v);
        cout << query(roots[u], roots[v], roots[lca], parents[lca], k) << '\n';
    }
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)
        go(tc++);
}
