#include <bits/stdc++.h>

using namespace std;

int A[2222222];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    int x = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        x ^= A[i];
    }

    int ans = x;
    for (int i = 0; i < N; i++) ans = max(ans, x^A[i]);

    cout << ans << ans << '\n';

    return 0;
}
