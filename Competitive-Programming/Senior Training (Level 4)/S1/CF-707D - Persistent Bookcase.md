# CodeForces - 707D

```cpp
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

struct nodeS;

extern nodeS *empty;

int n, m, q;

struct nodeS{
    int value, inversion;
    nodeS *left, *right;

    nodeS(){
        value = inversion = 0;
        left = right = this;
    }

    nodeS(nodeS *l, nodeS *r, int val, int inverse = 0){
        value = val;
        left = l;
        right = r;
        inversion = inverse;
    }

    void pushDown(int l, int r){
        if(inversion){
            int mid = l + (r - l) / 2;
            left = new nodeS(left->left, left->right, (mid - l + 1) - left->value, left->inversion ^ 1);
            right = new nodeS(right->left, right->right, (r - (mid + 1) + 1) - right->value, right->inversion ^ 1);
        }
        inversion = 0;
    }
};

nodeS *empty = new nodeS();

nodeS* updateShelf(nodeS *root, int op, int start, int end, int l = 1, int r = m){
    root->pushDown(l, r);

    if(start > r || end < l)
        return root;

    if(start <= l && end >= r) {
        if (op == 1)
            return new nodeS(root->left, root->right, (r - l + 1) - root->value, 1);
        else if (op == 2)
            return new nodeS(root->left, root->right, 0);
        else if (op == 3)
            return new nodeS(root->left, root->right, 1);
    }

    int mid = l + (r - l) / 2;
    nodeS *left = updateShelf(root->left, op, start, end, l, mid);
    nodeS *right = updateShelf(root->right, op, start, end, mid + 1, r);

    return new nodeS(left, right, left->value + right->value);
}


struct nodeB;

extern nodeB *emptyB;

struct nodeB{
    int value;
    nodeB *left, *right;
    nodeS *shelf;

    nodeB(){
        value = 0;
        left = right = this;
        shelf = new nodeS();
    }

    nodeB(nodeB *l, nodeB *r, int val, nodeS *sh){
        left = l;
        right = r;
        value = val;
        shelf = sh;
    }
};

nodeB *emptyB = new nodeB();

nodeB* updateBookcase(nodeB *root, int i, int j, int op, int l = 1, int r = n) {
    if (i < l || i > r)
        return root;

    if (l == r) {
        nodeS *newShelf;
        if (op == 1)
            newShelf = updateShelf(root->shelf, op, 1, m);
        else
            newShelf = updateShelf(root->shelf, op, j, j);

        return new nodeB(root->left, root->right, newShelf->value, newShelf);
    }

    int mid = l + (r - l) / 2;
    nodeB *left = updateBookcase(root->left, i, j, op, l, mid);
    nodeB *right = updateBookcase(root->right, i, j, op, mid + 1, r);

    return new nodeB(left, right, left->value + right->value, root->shelf);
}

nodeB *roots[N];

int timestamp;

void go(int tc = 0){
    cin >> n >> m >> q;

    roots[0] = emptyB;
    while(q--){
        int type, i, j, t;   cin >> type;

        timestamp++;
        if(type == 1){
            cin >> i >> j;
            roots[timestamp] = updateBookcase(roots[timestamp - 1], i, j, 3);
        }
        else if(type == 2) {
            cin >> i >> j;
            roots[timestamp] = updateBookcase(roots[timestamp - 1], i, j, 2);
        }
        else if(type == 3){
            cin >> i;
            roots[timestamp] = updateBookcase(roots[timestamp - 1], i, j, 1);
        }
        else if(type == 4){
            cin >> t;
            roots[timestamp] = roots[t];
        }

        cout << roots[timestamp]->value << '\n';
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
```
