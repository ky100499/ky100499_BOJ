#include <bits/stdc++.h>

using namespace std;

int A[1000], B[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, NN; cin >> N; NN = N*N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i*N+j] = A[i]+A[j];
    sort(B, B+NN);

    int ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int x = lower_bound(B, B+NN, A[i]-A[j])-B;
            if (x < NN && B[x] == A[i]-A[j]) ans = A[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
