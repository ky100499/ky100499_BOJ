#include <bits/stdc++.h>

using namespace std;

int N, M, A[8], ans[8];

void bt(int i, int n)
{
    if (n == M) {
        for (int j = 0; j < M; j++) cout << ans[j] << ' ';
        cout << '\n';
    }
    else {
        int v = 0;
        for (int j = i+1; j < N; j++) {
            if (v != A[j]) {
                v = A[j];
                ans[n] = A[j];
                bt(j, n+1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    bt(-1, 0);

    return 0;
}
