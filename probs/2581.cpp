#include <bits/stdc++.h>

using namespace std;

int P[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M, N; cin >> M >> N;

    fill(P, P+N+1, 1); P[0] = P[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (!P[i]) continue;
        for (int j = i*i; j <= N; j += i) P[j] = 0;
    }

    int s = 0, m = 1e9;
    for (int i = M; i <= N; i++) {
        if (P[i]) {
            s += i;
            m = min(m, i);
        }
    }

    if (s) cout << s << '\n' << m << '\n';
    else cout << "-1\n";

    return 0;
}
