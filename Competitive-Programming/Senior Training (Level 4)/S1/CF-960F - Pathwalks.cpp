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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m;

struct node;

extern node *empty;

struct node{
    int value;
    node *left, *right;

    node(){
        value = 0;
        left = right = this;
    }

    node(node *l, node *r, int val){
        value = val;
        left = l;
        right = r;
    }

};

node *empty = new node();

node *insertCost(node *root, int &val, int &start, int &end, int l = 0, int r = 1e5){
    if(start > r || end < l)
        return root;

    if(start <= l && end >= r)
        return new node(root->left, root->right, max(root->value, val + 1));

    int mid = l + (r - l) / 2;
    node *left = insertCost(root->left, val, start, end, l, mid);
    node *right = insertCost(root->right, val, start, end, mid + 1, r);

    return new node(left, right, max(left->value, right->value));
}


node *insertEdge(node *root, int &u, int &val, int &start, int &end, int l = 1, int r = n){
    if(u < l || u > r)
        return root;

    if(l == r){
        node *newCost = insertCost(root, val, start, end);
        return new node(newCost->left, newCost->right, newCost->value);
    }

    int mid = l + (r - l) / 2;
    node *left = insertEdge(root->left, u, val, start, end, l, mid);
    node *right = insertEdge(root->right, u, val, start, end, mid + 1, r);

    return new node(left, right, max(left->value, right->value));
}


int queryCost(node *root, int &start, int &end, int l = 0, int r = 1e5){
    if(start > r || end < l)
        return 0;

    if(start <= l && end >= r)
        return root->value;

    int mid = l + (r - l) / 2;
    int left = queryCost(root->left, start, end, l, mid);
    int right = queryCost(root->right, start, end, mid + 1, r);

    return max(left, right);
}


int queryNode(node *root, int &u, int &start, int &end, int l = 1, int r = n){
    if(u < l || u > r)
        return 0;

    if(l == r)
        return queryCost(root, start, end);

    int mid = l + (r - l) / 2;
    int left = queryNode(root->left, u, start, end, l, mid);
    int right = queryNode(root->right, u, start, end, mid + 1, r);

    return max(left, right);
}

node *roots[N];

void go(int tc = 0){
    cin >> n >> m;

    roots[0] = empty;
    for(int i = 1;i <= m;i++){
        int u, v, c;    cin >> u >> v >> c;

        int start = 0, end = c - 1;
        int mx = queryNode(roots[i - 1], u, start, end);
        roots[i] = insertEdge(roots[i - 1], v, mx, c, c);
    }

    cout << roots[m]->value << '\n';
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
