# SPOJ - TTM

You've been given N integers A[1], A[2],..., A[N]. On these integers, you need to implement the following operations:

C l r d: Adding a constant d for every {Ai | l <= i <= r}, and increase the timestamp by 1, this is the only operation that will cause the timestamp increase.

Q l r: Querying the current sum of {Ai | l <= i <= r}.

H l r t: Querying a history sum of {Ai | l <= i <= r} in time t.

B t: Back to time t. And once you decide return to a past, you can never be access to a forward edition anymore.

```cpp
#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct node;

extern node *empty;

struct node{
    ll value, lazyValue;
    bool isLazy;
    node *left, *right;

    node(){
        value = lazyValue = isLazy = 0;
        left = right = this;
    }

    node(node *l, node *r, ll val, ll lazyVal = 0, ll dirty = 0){
        left = l;
        right = r;
        value = val;
        lazyValue = lazyVal;
        isLazy = dirty;
    }

    node(node *old, ll lazyVal, int l, int r){
        left = old->left;
        right = old->right;
        value = old->value + (r - l + 1) * lazyVal;
        lazyValue = old->lazyValue + lazyVal;
        isLazy = 1;
    }

    void pushDown(int l, int r){
        if(isLazy){
            int mid = l + (r - l) / 2;
            left = new node(this->left, lazyValue, l, mid);
            right = new node(this->right, lazyValue, mid + 1, r);
            this->left = left;
            this->right = right;
        }
        lazyValue = isLazy = 0;
    }
};

node *empty = new node();

int n, m, a[N];

node* build(node *root, int l = 1, int r = n){
    if(l == r)
        return new node(root->left, root->right, a[l]);

    int mid = l + (r - l) / 2;
    node *left = build(root->left, l, mid);
    node *right = build(root->right, mid + 1, r);

    return new node(left, right, left->value + right->value);
}

node *update(node *root, int &val, int &start, int &end, int l = 1, int r = n){
    root->pushDown(l, r);

    if(start > r || end < l)
        return root;

    if(start <= l && end >= r)
        return new node(root->left, root->right, root->value + val * (r - l + 1), val, 1);

    int mid = l + (r - l) / 2;
    node *left = update(root->left, val, start, end, l, mid);
    node *right = update(root->right, val, start, end, mid + 1, r);

    return new node(left, right, left->value + right->value);
}

ll query(node *root, int &start, int &end, int l = 1, int r = n){
    root->pushDown(l, r);

    if(start > r || end < l)
        return 0;

    if(start <= l && end >= r)
        return root->value;

    int mid = l + (r - l) / 2;
    return query(root->left, start, end, l, mid) + query(root->right, start, end, mid + 1, r);
}

node *roots[N];
int timestamp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++)
        cin >> a[i];

    timestamp = 0;
    roots[timestamp] = build(empty);

    while(m--){
        char c; cin >> c;
        int l, r, d, t;

        if(c == 'Q'){
            cin >> l >> r;
            cout << query(roots[timestamp], l,r) << '\n';
        }
        else if(c == 'H'){
            cin >> l >> r >> t;
            cout << query(roots[t], l,r) << '\n';
        }
        else if(c == 'C'){
            cin >> l >> r >> d;
            roots[timestamp + 1] = update(roots[timestamp], d, l, r);
            timestamp++;
        }
        else if(c == 'B'){
            cin >> t;
            timestamp = t;
        }
    }
}
