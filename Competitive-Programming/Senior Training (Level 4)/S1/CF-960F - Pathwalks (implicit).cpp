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

    void extend(){
        if(left == this){
            left = new node();
            right = new node();
        }
    }
};

void insertCost(node *root, int &val, int &start, int &end, int l = 0, int r = 1e5){
    root->extend();

    if(start > r || end < l)
        return;

    if(start <= l && end >= r) {
        root->value = max(root->value, val + 1);
        return;
    }

    int mid = l + (r - l) / 2;
    insertCost(root->left, val, start, end, l, mid);
    insertCost(root->right, val, start, end, mid + 1, r);

    root->value = max(root->left->value, root->right->value);
}


void insertEdge(node *root, int &u, int &val, int &start, int &end, int l = 1, int r = n){
    root->extend();

    if(u < l || u > r)
        return;

    if(l == r){
        insertCost(root, val, start, end);
        return;
    }

    int mid = l + (r - l) / 2;
    insertEdge(root->left, u, val, start, end, l, mid);
    insertEdge(root->right, u, val, start, end, mid + 1, r);

    root->value = max(root->left->value, root->right->value);
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

    node *root = new node();
    for(int i = 1;i <= m;i++){
        int u, v, c;    cin >> u >> v >> c;

        int start = 0, end = c - 1;
        int mx = queryNode(root, u, start, end);
        insertEdge(root, v, mx, c, c);
    }

    cout << root->value << '\n';
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
