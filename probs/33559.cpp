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
        for (int i = 0; i < min(v, B[k]); i++) cout << k << ' ';
    }
    for (auto [k, v] : A) {
        for (int i = 0; i < v-B[k]; i++) cout << k << ' ';
    }
    cout << '\n';

    for (auto [k, v] : B) {
        for (int i = 0; i < min(v, A[k]); i++) cout << k << ' ';
    }
    for (auto [k, v] : B) {
        for (int i = 0; i < v-A[k]; i++) cout << k << ' ';
    }
    cout << '\n';

    return 0;
}
