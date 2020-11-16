# Knapsack
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 2e5+5, M = 3e3+5, OO = 0x3f3f3f3f;

int mem[N][M];

int solve(int lst, int rem){
    if(lst == -1)   return 0;
    int& ret = mem[lst][rem];
    if(~ret)    return ret;
    ret = solve(lst-1, rem);    
    if(W[lst] <= rem){
        // ret = max(ret, P[lst] + solve(lst-1, rem-W[lst]));
        int ch2 = P[lst];
        int newRem = rem - W[lst];
        ch2 += solve(lst-1, newRem);
        ret = max(ret, ch2);
    }
    return ret;
}

int main(){
    return 0;
}
```

# Coin Change
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 3e1+5, M = 1e4+5, OO = 0x3f3f3f3f;

int m, n;
int coin[N];

long long mem[N][M];
long long solve(int lst, int rem){
    if(rem == 0)    return 1;
    if(rem < 0 || lst == -1) return 0;
    long long& ret = mem[lst][rem];
    if(~ret)    return ret;
    ret = solve(lst-1, rem) + solve(lst, rem-coin[lst]);
    return ret;
}

int main(){
    // freopen("money.in", "rt", stdin);
    // freopen("money.out", "wt", stdout);
    scanf("%d %d", &m, &n);
    for(int i = 0 ; i < m ; ++i)    scanf("%d", coin+i);
    memset(mem, -1, sizeof mem);
    printf("%lld\n", solve(m-1, n));
    return 0;
}
```

# LIS
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 3e1+5, M = 1e4+5, OO = 0x3f3f3f3f;

int n, A[N];
int mem[N];

int solve(int lst){
    int& ret = mem[lst];
    if(~ret)    return ret;
    ret = 1;
    for(int prev = 0 ; prev < lst ; ++prev){
        if(A[prev] >= A[lst])   continue;
        int v = solve(prev);
        ret = max(ret, v+1);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)    scanf("%d", A+i);
    memset(mem, -1, sizeof mem);
    int lis = 0;
    for(int i = 0 ; i < n ; ++i){
        lis = max(lis, solve(i));
    }
    printf("%d\n", lis);
    return 0;
}
```

# Matrix Chain Multiplication
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 3e3+5, M = 1e4+5, OO = 0x3f3f3f3f;

int n;
int R[N], C[N];

long long mem[N][N];
long long solve(int l, int r){
    if(r-l == 1)    return 0;
    long long& ret = mem[l][r];
    if(~ret)    return ret;
    ret = 1ll*OO*OO;
    for(int m = l+1 ; m < r ; ++m){
        ret = min(ret, solve(l, m) + solve(m, r) + R[l]*C[r-1]*R[m]);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)    scanf("%d %d", R+i, C+i);
    memset(mem, -1, sizeof mem);
    printf("%lld\n", solve(0, n));
    return 0;
}
```

# Traveling Salesman Problem
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 21, M = (1<<N), OO = 0x3f3f3f3f;

int n, st;
int mat[N][N];
int mem[N][M];

void floyd(){
    for(int k = 0 ; k < n ; ++k)
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}

int solve(int cur, int msk){
    if(msk == (1<<n)-1) return mat[cur][st];
    int& ret = mem[cur][msk];
    if(~ret)    return ret;
    ret = OO;
    for(int nxt = 0 ; nxt < n ; ++nxt){
        if((msk>>nxt)&1)    continue;       //City Number "nxt" is Visited
        ret = min(ret, mat[cur][nxt] + solve(nxt, msk|(1<<nxt)));
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &st);
    // memset(mat, OO, sizeof mat);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            scanf("%d", mat[i]+j);
    memset(mem, -1, sizeof mem);
    floyd();
    printf("%d\n", solve(st, (1<<st)));
    return 0;
}
```

# Longest Common Sub-sequence + Path Printing
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 1e3+5, M = 1e5+5, OO = 0x3f3f3f3f;

char s1[N], s2[N];

int mem[N][N];
int solve(int i, int j){
    if(!s1[i] || !s2[j])    return 0;
    int& ret = mem[i][j];
    if(~ret)    return ret;
    if(s1[i] == s2[j])  return ret = 1+solve(i+1, j+1);
    return ret = max(solve(i+1, j), solve(i, j+1));
}

void print(int i, int j){
    if(!s1[i] || !s2[j])    return puts(""), void();
    if(solve(i, j) == solve(i+1, j+1)+1){
        printf("%c", s1[i]);
        print(i+1, j+1);
    }else if(solve(i, j) == solve(i+1, j)){
        print(i+1, j);
    }else{
        print(i, j+1);
    }
}

int main(){
    scanf("%s %s", s1, s2);
    memset(mem, -1, sizeof mem);
    printf("%d\n", solve(0, 0));
    print(0, 0);
    return 0;
}
```


# MCM + Path Printing
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 3e3+5, M = 1e4+5, OO = 0x3f3f3f3f;

int n;
int R[N], C[N];

long long mem[N][N];
long long solve(int l, int r){
    if(r-l == 1)    return 0;
    long long& ret = mem[l][r];
    if(~ret)    return ret;
    ret = 1ll*OO*OO;
    for(int m = l+1 ; m < r ; ++m){
        ret = min(ret, solve(l, m) + solve(m, r) + R[l]*C[r-1]*R[m]);
    }
    return ret;
}

void print(int l, int r){
    if(r - l == 1){
        printf("%c", 'A'+l);
        return;
    }
    for(int m = l+1 ; m < r ; ++m){
        if(solve(l, r) == solve(l, m) + solve(m, r) + R[l]*C[r-1]*R[m]){
            printf("(");
            print(l, m);
            printf("*");
            print(m, r);
            printf(")");
            return;
        }   
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)    scanf("%d %d", R+i, C+i);
    memset(mem, -1, sizeof mem);
    // printf("%lld\n", solve(0, n));
    print(0, n);
    puts("");
    return 0;
}
```

# Knapsack (Iterative)
```cpp
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e2+2, M = 256+5, OO = 0x3f3f3f3f;

int n, W[N], P[N];

int mem[N][N];

int KS(int i = 0, int rem = k){
    if(i == n)  return 0;
    int& ret = mem[i][rem];
    if(~ret)    return ret;
    return ret = max(KS(i+1, rem),
     (rem >= W[i] ? KS(i+1, rem-W[i])+P[i]: 0));
}

int dp[2][N];
int KSIterative(){
    fill(dp[(n)&1], dp[(n)&1]+N, 0);
    for(int i = n-1 ; ~i ; --i){
        for(int rem = 0 ; rem <= k ; ++rem){
            int& ret = dp[(i)&1][rem];
            ret = dp[(i+1)&1][rem];
            if(rem >= W[i]) ret = max(ret, dp[(i+1)&1][rem-W[i]]+P[i]);
        }
    }
    return dp[0][k];
}

int main(){
    solve();
    return 0;
}
```

# Coin Change (Iterative)
```cpp
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e2+2, M = 256+5, OO = 0x3f3f3f3f;

int n = 6, coins[] = {1, 5, 10, 20, 50, 100};
int v;

// ll mem[]
// ll solve(int i = 0, int rem = v){
//     if(i == n)  return rem == 0;
//     int& ret = mem[i][rem];
//     if(~ret)    return ret;
//     return ret = solve(i+1, rem)
//      + (rem >= coins[i]? solve(i, rem-coins[i]) : 0);
// }

ll dp[N][N];
ll coinChangeIterative(){
    fill(dp[n], dp[n]+N, 0);
    dp[n][0] = 1;
    for(int i = n-1 ; ~i ; --i){
        for(int rem = 0 ; rem <= v ; ++rem){
            ll& res = dp[i][rem];
            res = dp[i+1][rem];
            if(coins[i] <= rem) res += dp[i][rem-coins[i]];
        }
    }
    return dp[0][v];
}

int coinChangeIterative2(){
    dp[0] = 1;
    for(int i = n-1 ; ~i ; --i){
        for(int rem = coins[i] ; rem <= v ; ++rem){
                dp[rem] += dp[rem-coins[i]];
        }
    }
}

int main(){
    scanf("%d", &v);
    printf("%lld\n", coinChangeIterative());
    return 0;
}
```

# LIS (Iterative)
```cpp
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e2+2, M = 256+5, OO = 0x3f3f3f3f;

int n, A[N];
int dp[2][N];
int LISIterative(){
    A[0] = -OO;
    for(int i = n ; i > 0 ; --i){
        for(int p = 0 ; p < i ; ++p){
            int& ret = dp[i&1][p];
            ret = dp[(i+1)&1][p];
            if(A[i] > A[p]) ret = max(ret, dp[(i+1)&1][i]+1);
        }
    }
    return dp[1][0];
}

int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i)    scanf("%d", A+i);
    printf("%d\n", LISIterative());
    return 0;
}
```
