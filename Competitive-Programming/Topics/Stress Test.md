# Stress Test


## Code (for Windows)

```cpp
#include <bits/stdc++.h>

using namespace std;

void gen(){
    ofstream cout("in.in");
    int t = 10000;
    cout << t << '\n';
    while(t--) {
        int a, b, c;
        a = rand() % 100000000 + 1;
        b = rand() % 1000000000 + 1;
        c = rand() % 1000000000 + 1;
        if (a > b)swap(a, b);
        cout << a << " " << b << " " << c << endl;
    }
}
int main() {
    int tc = 0;
    system("g++  ac.cpp -o ac");
    system("g++  wa.cpp -o wa");
    while(++tc) {
        gen();
        cerr << tc << endl;

        system("ac.exe < in.in > ac.out");
        system("wa.exe < in.in > wa.out");

        ifstream acs("ac.out"), was("wa.out");
        string ac, wa;
        getline(acs, ac, (char) EOF);
        getline(was, wa, (char) EOF);
        if (wa != ac) break;
    }
}
```


## Code (for Linux)

```cpp
#include <bits/stdc++.h>

using namespace std;

void gen(){
    ofstream cout("in.in");
    int t = 2;
    cout << t << endl;
    while(t--){
        int n = rand()%5+1, m = rand()%7+1;
        cout << n << " " << m << endl;
        while(m--){
            int u = rand()%n+1, v = rand()%n+1, c = rand()%10-5;
            cout << u << " " << v << " " << c << endl;
        }
    }
}

int main(){
    int tc = 0;
    system("g++ -O2 -std=c++14 c.cpp -o wa");
    system("g++ -O2 -std=c++14 ac.cpp -o ac");
    while(++tc){
        gen();
        cerr << tc << endl;

        system("./wa < i.in > wa.out");
        system("./ac < i.in > ac.out");

        ifstream acs("ac.out"), was("wa.out");
        string ac, wa;
        getline(acs, ac, (char)EOF);
        getline(was, wa, (char)EOF);
        if(wa != ac)    break;
    }
}
```
