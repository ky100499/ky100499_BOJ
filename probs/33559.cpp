#include <bits/stdc++.h>

using namespace std;

map<int, int> A, B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N*2; i++) {
        int n; cin >> n;
        (i/N ? B : A)[n]++;
    }

    int ans = 0;
    for (auto [k, v] : A) ans += min(v, B[k]);
    cout << ans << '\n';

    for (auto [k, v] : A) {
        while (A[k] > B[k]) {
            cout << k << ' ';
            A[k]--;
        }
    }
    for (auto [k, v] : A) {
        for (int i = 0; i < v; i++) cout << k << ' ';
    }
    cout << '\n';

    for (auto [k, v] : B) {
        while (B[k] > A[k]) {
            cout << k << ' ';
            B[k]--;
        }
    }
    for (auto [k, v] : B) {
        for (int i = 0; i < v; i++) cout << k << ' ';
    }
    cout << '\n';

    return 0;
}
