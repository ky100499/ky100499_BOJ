#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int A[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    memset(A, 0, sizeof A);
    A[1][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < i; j++)
            A[i][j] = (A[i-1][j-1] + 2*A[i-1][j] + A[i-1][j+1]) % MOD;

    int s = 0;
    for (int i = 1; i < N; i++) s += A[N][i];
    cout << 2 * s % MOD << '\n';

    return 0;
}
