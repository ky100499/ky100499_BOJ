#include <bits/stdc++.h>

using namespace std;

int A[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N, greater<int>());

    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, A[i]*(i+1));

    cout << ans << '\n';

    return 0;
}
