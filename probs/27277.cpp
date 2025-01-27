#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int i = 0, j = N-1, ans = 0;
    while (i < j) ans += A[j--] - A[i++];
    ans += A[j];

    cout << ans << '\n';

    return 0;
}
