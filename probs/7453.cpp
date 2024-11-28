#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 4000;

int A[MAX], B[MAX], C[MAX], D[MAX], AB[MAX*MAX], CD[MAX*MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[i*N+j] = A[i]+B[j];
            CD[i*N+j] = C[i]+D[j];
        }
    }
    sort(AB, AB+N*N);
    sort(CD, CD+N*N);

    int *ptr = AB;
    ll ans = 0;
    while (ptr - AB < N*N) {
        int v = *ptr;
        ptr = upper_bound(AB, AB+N*N, v);
        ll n1 = ptr - lower_bound(AB, AB+N*N, v),
           n2 = upper_bound(CD, CD+N*N, -v) - lower_bound(CD, CD+N*N, -v);
        ans += n1*n2;
    }
    cout << ans << '\n';

    return 0;
}
