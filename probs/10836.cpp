#include <bits/stdc++.h>

using namespace std;

const int MAX = 700;

int A[MAX][MAX],
    B[2*MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M, N; cin >> M >> N;

    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);

    while (N--) {
        int x = 0;
        for (int i = 0; i < 3; i++) {
            int n; cin >> n;
            x += n;
            B[x]++;
        }
    }

    A[M-1][0] = B[0]+1;
    for (int i = 1; i < M; i++) A[M-i-1][0] = A[M-i][0] + B[i];
    for (int i = 1; i < M; i++) A[0][i] = A[0][i-1] + B[i+M-1];
    for (int i = 1; i < M; i++)
        for (int j = 1; j < M; j++) A[i][j] = A[0][j];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) cout << A[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
