#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;

int A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int l = 0, h = N-1;
        while (l < h) {
            if (l == i) {
                l++;
                continue;
            }
            if (h == i) {
                h--;
                continue;
            }

            int s = A[l]+A[h];
            if (s < A[i]) l++;
            else if (s > A[i]) h--;
            else {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
