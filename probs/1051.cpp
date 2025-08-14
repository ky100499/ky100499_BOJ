#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

char A[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    int ans = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = ans; k < min(N-i, M-j); k++)
                if (A[i][j] == A[i+k][j] && A[i][j] == A[i][j+k] && A[i][j] == A[i+k][j+k])
                    ans = k+1;
    cout << ans*ans << '\n';

    return 0;
}
