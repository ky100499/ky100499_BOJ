#include <bits/stdc++.h>

using namespace std;

int A[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int ub0 = upper_bound(A, A+N, 0) - A,
        ub1 = upper_bound(A, A+N, 1) - A;

    int ans = 0;
    int i = 0, j = N-1;
    while (i+1 < ub0) {
        ans += A[i]*A[i+1];
        i += 2;
    }
    while (j-1 >= ub1) {
        ans += A[j]*A[j-1];
        j -= 2;
    }
    while (i <= j) ans += A[i++];

    cout << ans << '\n';

    return 0;
}
