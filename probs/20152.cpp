#include <bits/stdc++.h>

using namespace std;
using pi = tuple<int, int, int, int, int>;

long long A[31][31];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int H, N; cin >> H >> N;

    N = abs(H-N);
    memset(A, 0, sizeof A); A[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        A[i][0] = 1;
        for (int j = 1; j < i; j++) {
            A[i][j] = A[i-1][j] + A[i][j-1];
        }
        A[i][i] = A[i][i-1];
    }

    cout << A[N][N] << '\n';

    return 0;
}
