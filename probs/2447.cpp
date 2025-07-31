#include <bits/stdc++.h>

using namespace std;

const int MAX = 2187;

char A[MAX][MAX];

void solve(int n, int x, int y)
{
    if (n == 1) {
        A[x][y] = '*';
        return;
    }

    n /= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i * j == 1) continue;
            solve(n, x+i*n, y+j*n);
        }
    }

    for (int i = x+n; i < x+2*n; i++)
        for (int j = y+n; j < y+2*n; j++)
            A[i][j] = ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    solve(N, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << A[i][j];
        cout << '\n';
    }

    return 0;
}
