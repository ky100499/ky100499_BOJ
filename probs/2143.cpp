#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1000;

int A[MAX+1], B[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T, N, M; cin >> T >> N;
    A[0] = B[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        B[i] += B[i-1];
    }

    vector<int> MA, MB; MA.reserve(N*N/2); MB.reserve(M*M/2);
    for (int i = 0; i < N; i++)
        for (int j = i+1; j <= N; j++)
            MA.push_back(A[j]-A[i]);
    for (int i = 0; i < M; i++)
        for (int j = i+1; j <= M; j++)
            MB.push_back(B[j]-B[i]);
    sort(MB.begin(), MB.end());

    ll ans = 0;
    for (int v : MA)
        ans += upper_bound(MB.begin(), MB.end(), T-v) - lower_bound(MB.begin(), MB.end(), T-v);
    cout << ans << '\n';

    return 0;
}
