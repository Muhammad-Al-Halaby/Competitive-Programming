# Tree Diameter, Center and Isomorphism

# Tree Diameter
- The longest path in a tree.


# Code
```cpp
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
	int head[N], nxt[M], to[M], ne, n;
	void init(int n) {
		memset(head, -1, n * sizeof(head[0]));
		ne = 0;
		this->n = n;
	}
	void addEdge(int f, int t) {
		nxt[ne] = head[f];
		to[ne] = t;
		head[f] = ne++;
	}
	void addBiEdge(int f, int t) {
		addEdge(f, t);
		addEdge(t, f);
	}
	int addNode() {
		head[++n] = 0;
		return n;
	}
} adj;

int vis[N], vid;

pii dfsDiameter(int u, int p){
    vis[u] = vid;

    int diameter = 0, mxDepth[3] = {-1, -1, -1};
    neig(adj, u, e, v){
        if(v == p)  continue;
        auto p = dfsDiameter(v, u);
        diameter = max(diameter, p.F);
        mxDepth[0] = p.S + 1;
        sort(mxDepth, mxDepth + 3);
    }

    for(int i = 0;i < 3;i++)    if(mxDepth[i] == -1)    mxDepth[i] = 0;

    diameter = max(diameter, mxDepth[1] + mxDepth[2]);

    return {diameter, mxDepth[2]};
}
```

# Tree Center
- The node(s) which minimizes the length of the path from it to any node.

- Tree center splits the diameter into to parts (d / 2) or (d / 2 + 1)


```cpp
#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("meciul.in","r",stdin);
    freopen("meciul.out","w",stdout);
#endif
}

const int N = 1e6 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;

int n;

struct Graph{

    int ne, head[N], nxt[M], to[M] , DEG[N];

    void initGraph(){
        memset(head, -1, n * sizeof head[0]);
        memset(DEG, 0, n * sizeof DEG[0]);
        ne = 0;
    }

    void addEdge(int f, int t){
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
        DEG[t]++;
    }

    void addBiEdge(int u, int v){
        addEdge(u, v);
        addEdge(v, u);
    }
};


Graph A, B;

string getNodeCanoniaclForm(int u, vector< vector<string> > &subCan){
    sort(subCan[u].begin(), subCan[u].end());
    string nodeRep = "(";
    for(string s : subCan[u])
        nodeRep += s;
    nodeRep += ")";
    return nodeRep;
}

string treeCanonicalForm(Graph &G){
	queue<int> LeafNodes;
	int remNodes = n;
    for(int i =  0;i < n;i++)
        if(G.DEG[i] <= 1)
            LeafNodes.push(i);

    vector< vector<string> > subCan(n);

    while(remNodes > 2){
        int sz = LeafNodes.size();
        while(sz--){
            int u = LeafNodes.front();  LeafNodes.pop();
            string nodeRep = getNodeCanoniaclForm(u, subCan);
            for(int k = G.head[u]; ~k ; k = G.nxt[k]){
                int v = G.to[k];
                subCan[v].push_back(nodeRep);
                if(--G.DEG[v] == 1)
                    LeafNodes.push(v);
            }
            --remNodes;
        }
    }

    int c1 = LeafNodes.front();  LeafNodes.pop();
    int c2 = (LeafNodes.empty() ? -1 : LeafNodes.front());

    string s1 = getNodeCanoniaclForm(c1, subCan);
    string s2 = (c2 == -1 ? "" : getNodeCanoniaclForm(c2, subCan));

    if(c2 == -1)
        return s1;

    subCan[c1].PB(s2);
    subCan[c2].PB(s1);

    return min(getNodeCanoniaclForm(c1, subCan), getNodeCanoniaclForm(c2, subCan));
}

int u, v;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;
        A.initGraph();  B.initGraph();
        for(int i = 0;i < n - 1;i++){
            cin >> u >> v;
            --u, --v;
            A.addBiEdge(u ,v);
        }

        for(int i = 0;i < n - 1;i++){
            cin >> u >> v;
            --u, --v;
            B.addBiEdge(u ,v);
        }

        cout << (treeCanonicalForm(A) == treeCanonicalForm(B) ? "YES\n" : "NO\n");

    }
}
```
