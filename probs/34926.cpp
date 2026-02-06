#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int A[MAX];
char C[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> C[i];

    memset(A, 0, sizeof A); A[0] = 1;
    for (int i = 0; i < N-1; i++) {
        if (!A[i]) continue;
        if (C[i+1] == '_') A[i+1] = 1;
        if (i+K < N && C[i+K] == '_') A[i+K] = 1;
    }

    cout << (A[N-1] ? "YES" : "NO") << '\n';

    return 0;
}
