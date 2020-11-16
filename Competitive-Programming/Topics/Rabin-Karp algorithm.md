# Rabin-Karp Algorithm


## Notes
1. Base is better to be prime.
1. Please read the parameters carefully before you call any method.
1. You can preprocess the powers with the chosen base.
1. Use double hashing to lower the probability of collisions.


```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define R first.first
#define C first.second
#define S second

const int N = 1e6+5, M = 4e4+7;
const double EPS = 1e-6;
const int OO = 0x3f3f3f3f;

ll fixMod(ll a, ll b){
    return (a%b + b)%b;
}

void pushBack(ll& h, ll base, ll mod, char c){
    h = ((h*base)%mod + c)%mod;
}

void pushFront(ll& h, ll p, ll mod, char c){
    h = (h + (c*p)%mod)%mod;
}

void popFront(ll& h, ll p, ll mod, char c){
    h = fixMod((h - (p*c)%mod), mod);
}

void popBack(ll& h, ll inv, ll mod, char c){
    h = (fixMod(h-c, mod)*inv)%mod;
}

ll power(ll a, ll b, ll m){
    if(!b)  return 1;
    ll t = power(a, b>>1, m);
    return ((t*t)%m * (b&1 ? a : 1))%m;
}

int n, m;
char s1[N], s2[N];

bool f;

int main(){
    while(~scanf("%d", &n)){
        scanf("%s %s", s1, s2);
        if(f)   puts("");
        f = 1;
        m = strlen(s2);
        ll hp = 0; //hash of s1
        ll base = 131; //base for hashing
        ll mod = 1e9+7; //modulo for hashing
        if(n > m){
            continue;
        }
        ll hw = 0; //hash of s2
        ll p = 1;
        for(int i = 0 ; i < n ; ++i){
            pushBack(hp, base, mod, s1[i]);
            pushBack(hw, base, mod, s2[i]);
            if(i)   p = (p*base)%mod;
        }
        vector<int> ans;
        if(hp == hw)    ans.push_back(0);
        for(int j = n ; j < m ; ++j){
            popFront(hw, p, mod, s2[j-n]);
            pushBack(hw, base, mod, s2[j]);
            if(hw == hp)
                ans.push_back(j-n+1);
        }
        for(int x : ans)
            printf("%d\n", x);
    }
    return 0;
}
```


## Count the number of unique substrings of size k (double hashing)

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define R first.first
#define C first.second
#define S second

const int N = 1e5+5, M = 4e4+7;
const double EPS = 1e-6;
const int OO = 0x3f3f3f3f;

ll fixMod(ll a, ll b){
    return (a%b + b)%b;
}

void pushBack(ll& h, ll base, ll mod, char c){
    h = ((h*base)%mod + c)%mod;
}

void pushFront(ll& h, ll p, ll mod, char c){
    h = (h + (c*p)%mod)%mod;
}

void popFront(ll& h, ll p, ll mod, char c){
    h = fixMod((h - (p*c)%mod), mod);
}

void popBack(ll& h, ll inv, ll mod, char c){
    h = (fixMod(h-c, mod)*inv)%mod;
}

ll power(ll a, ll b, ll m){
    if(!b)  return 1;
    ll t = power(a, b>>1, m);
    return ((t*t)%m * (b&1 ? a : 1))%m;
}

int t, n, k;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %s", &n, &k, s);
        ll hw1 = 0, base1 = 129, mod1 = 1e9+7, p1 = 1;
        ll hw2 = 0, base2 = 131, mod2 = 1e9+9, p2 = 1;
        for(int i = 0 ; i < k ; ++i){
            pushBack(hw1, base1, mod1, s[i]);
            pushBack(hw2, base2, mod2, s[i]);
            if(i) p1 = (p1*base1)%mod1;
            if(i) p2 = (p2*base2)%mod2;
        }
        set<pair<int, int> > st;
        st.insert({hw1, hw2});
        for(int i = k ; i < n ; ++i){
            popFront(hw1, p1, mod1, s[i-k]);
            popFront(hw2, p2, mod2, s[i-k]);
            pushBack(hw1, base1, mod1, s[i]);
            pushBack(hw2, base2, mod2, s[i]);
            st.insert({hw1, hw2});
        }
        printf("%d\n", st.size());
    }
    return 0;
}
```
