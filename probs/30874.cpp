#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        int s; cin >> s;
        M = max(M, s);
    }

    cout << N + M - 1 << '\n';

    return 0;
}
