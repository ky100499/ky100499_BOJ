#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 500000;

int V[MAX+1][2] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    fill(&V[0][0], &V[MAX+1][2], 9999);

    queue<pi> q; q.emplace(N, 0); V[N][0] = 0;
    while (!q.empty()) {
        auto [n, t] = q.front(); q.pop();
        for (int nxt : {n-1, n+1, 2*n}) {
            if (0 <= nxt && nxt <= MAX && V[nxt][(t+1)%2] > t+1) {
                V[nxt][(t+1)%2] = t+1;
                q.emplace(nxt, t+1);
            }
        }
    }

    int t = 0;
    while (1) {
        if (K > MAX) {
            cout << -1 << '\n';
            break;
        }
        else if (V[K][t%2] <= t) {
            cout << t << '\n';
            break;
        }
        K += ++t;
    }

    return 0;
}
