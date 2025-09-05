#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(A, 0, sizeof A);
    for (int i = 0; i < N; i++) {
        int L, H; cin >> L >> H;
        A[L] = H;
    }

    int l = 0, h = 0, ans = 0;

    for (int i = 1; i <= 1000; i++) {
        if (A[i]) {
            if (h < A[i]) {
                ans += (i - l) * h;
                l = i; h = A[i];
            }
        }
    }

    l = h = 0;

    for (int i = 1000; i; i--) {
        if (A[i]) {
            if (h <= A[i]) {
                ans += (l - i) * h;
                l = i; h = A[i];
            }
        }
    }

    cout << ans + h << '\n';

    return 0;
}
