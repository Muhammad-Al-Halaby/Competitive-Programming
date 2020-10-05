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

int query(node *leftroot, node *rightroot, int &start, int &end, int l = -1e9, int r = 1e9){
    if(end < l || start > r)  return 0;

    if(start <= l && end >= r)
        return rightroot->freq - leftroot->freq;

    int mid = l + (r - l) / 2;

    return query(leftroot->left, rightroot->left, start, end, l, mid) + query(leftroot->right, rightroot->right, start, end, mid + 1, r);
}

int last[M];

void go(int tc = 0){

    int n;  cin >> n;

    int prev[N];
    for(int i = 1;i <= n;i++){
        int x;  cin >> x;
        prev[i] = last[x];
        last[x] = i;
    }

    node *roots[n + 1];

    roots[0] = empty;
    for(int i = 1;i <= n;i++)
        roots[i] = insert(roots[i - 1], prev[i]);

    int q;  cin >> q;
    while(q--){
        int l, r;   cin >> l >> r;
        int start = 0, end = l - 1;
        cout << query(roots[l - 1], roots[r], start, end) << '\n';
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
