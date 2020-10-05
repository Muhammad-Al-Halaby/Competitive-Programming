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

const int N = 1e5 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct node;

extern node *empty;

struct node{
    int freq;
    node *left, *right;

    node(){
        freq = 0;
        left = right = this;
    }

    node(node *l, node *r, int cnt){
        freq = cnt;
        left = l;
        right = r;
    }

};

node *empty = new node;

node* insert(node *root, int &val, int l = -1e9, int r = 1e9){
    if(val < l || val > r)  return root;

    if(l == r)
        return new node(root->left, root->right, root->freq + 1);


    int mid = l + (r - l) / 2;
    node *left = insert(root->left, val, l, mid);
    node *right = insert(root->right, val, mid + 1, r);

    return new node(left, right, left->freq + right->freq);
}

int query(node *leftroot, node *rightroot, int k, int l = -1e9, int r = 1e9){
    if(l == r)
        return l;

    int mid = l + (r - l) / 2;
    int left = rightroot->left->freq - leftroot->left->freq;
    if(left >= k)
        return query(leftroot->left, rightroot->left, k, l, mid);
    else
        return query(leftroot->right, rightroot->right, k - left, mid + 1, r);
}

void go(int tc = 0){
    int n, q;   cin >> n >> q;

    node *roots[N];

    roots[0] = empty;

    for(int i = 1, x;i <= n;i++){
        cin >> x;
        roots[i] = insert(roots[i - 1], x);
    }

    while(q--){
        int l, r, k;    cin >> l >> r >> k;
        cout << query(roots[l - 1], roots[r], k) << '\n';
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
