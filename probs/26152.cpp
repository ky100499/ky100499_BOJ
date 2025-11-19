#include <bits/stdc++.h>

using namespace std;

const int MAX = 250000;

int A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, D = 2e9; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        A[i] = D = min(D, A[i]-b);
    }

    int Q; cin >> Q;
    while (Q--) {
        int w; cin >> w;
        cout << upper_bound(A, A+N, w, greater<int>())-A << '\n';
    }

    return 0;
}
