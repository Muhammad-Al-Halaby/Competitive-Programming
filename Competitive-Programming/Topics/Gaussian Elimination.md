# Gaussian Elimination

Gaussian Elimination for solving a system of linear algebraic equations.

The following code determines if the system has no solution, exactly one solution or infinite number of solutions. And in case it has at least one solution, it finds any of them.

```cpp
#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define EPS double (1e-9)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
vector<vector<double>> matrix; // [n * (n + 1)] matrix, has n equations (rows), each equation has n coefficients (LHS) and the constant (RHS) (columns)
vector<double> solution;

int gaussian_elimination() {    // returns the number of solutions
    // convert the linear system of equations into row echelon form
    for (int i = 0; i < n; i++) {
        int mx = i; // mx = index of a row that has the largest value at index i (looking for a non-zero)
        for (int j = i + 1; j < n; j++)
            if (fabs(matrix[mx][i]) < fabs(matrix[j][i]))
                mx = j;

        swap(matrix[i], matrix[mx]);

        // divide the whole row by matrix[i][i]
        for (int j = n; j >= i; j--)
            matrix[i][j] /= matrix[i][i];

        // convert the index i to a zero in the next rows
        for (int j = i + 1; j < n; j++)
            for (int k = n; k >= i; k--)
                matrix[j][k] += matrix[i][k] * -matrix[j][i];
    }

    // fine the solution by back substitution
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = n - 1; j > i; j--) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    // check if the solution doesn't satisfy the equations
    int zeroRows = 0;
    for(int i = 0;i < n;i++){
        double sum = 0;
        bool zero = 1;
        for(int j = i;j < n;j++) {
            sum += solution[j] * matrix[i][j];
            zero &= (matrix[i][j] == 0);
        }

        if(zero)    zeroRows++;

        if(fabs(sum - matrix[i][n]) > EPS)
            return 0;
    }

    return (zeroRows ? OO : 1);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    matrix.resize(n, vector<double>(n + 1));
    solution.resize(n);

    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            cin >> matrix[i][j];
        }
    }

    int number_of_solutions = gaussian_elimination();

    cout << "Number of solutions = " << number_of_solutions << endl;
    for(int i = 0;i < n;i++)
        cout << fixed << setprecision(5) << "x" << i << " = " << solution[i] << endl;
}
```


# Tutorials

- https://cp-algorithms.com/linear_algebra/linear-system-gauss.html

- https://onedrive.live.com/?authkey=%21AEx4zb00w17bKfQ&cid=2D62AC61BB1A2826&id=2D62AC61BB1A2826%21127&parId=root&o=OneUp

- https://codeforces.com/blog/entry/68953

- https://www.hackerearth.com/practice/notes/gaussian-elimination/

- https://codeforces.com/blog/entry/60003

# Problems

- https://acm.timus.ru/problem.aspx?space=1&num=1042 [[My solution](https://www.ideone.com/iUQ4k3)]
