#include <bits/stdc++.h>

using namespace std;

int A[300000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    cout << (N == 1 ? A[0] : A[N-2]) << '\n';

    if (N > 1) {
        int i = 0, j = N-3, m = A[(i+j)/2];
        while (i < j) cout << A[i++] << ' ' << m << ' ' << A[j--] << '\n';
        cout << m << ' ' << A[N-2] << ' ' << A[N-1] << '\n';
    }

    return 0;
}
