#include <bits/stdc++.h>

using namespace std;

const int MAX = 250000;
const double ERR = 1e-8;

double A[MAX]; int E[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        E[i] = A[i] = log2(A[i]);
        A[i] -= E[i];
    }

    long long ans = 0;
    for (int i = 1; i < N; i++) {
        if (E[i-1] >= E[i]) {
            int d = E[i-1] - E[i] + (A[i-1] - A[i] > ERR);
            E[i] += d;
            ans += d;
        }
    }

    cout << ans << '\n';

    return 0;
}
