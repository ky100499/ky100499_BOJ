#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5+1;

int P[MAX], S[MAX][2], O[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    fill(P, P+MAX, 1); P[0] = P[1] = 0;
    memset(S, 0, sizeof S);
    int o = 0;
    for (ll i = 2; i < MAX; i++) {
        O[i] = o;
        for (int j = 0; j < 2; j++) S[i][j] = S[i-1][j];
        if (P[i]) {
            for (ll j = i*i; j < MAX; j += i) P[j] = 0;
            S[i][o] += i;
            o ^= 1;
        }
    }

    while (N--) {
        int a, b; cin >> a >> b;
        cout << 3*(S[b][O[a]] - S[a-1][O[a]]) - (S[b][O[a]^1] - S[a-1][O[a]^1]) << '\n';
    }

    return 0;
}
