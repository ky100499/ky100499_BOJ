#include <bits/stdc++.h>

using namespace std;
using qi = tuple<int, int, int, int>;

const int MAX = 20,
          INF = 1e9;

int W1[MAX][MAX], W2[MAX][MAX],
    d1[MAX], d2[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ipt; cin >> ipt;
            W1[i][j] = ipt == '.' ? -1 : ipt - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ipt; cin >> ipt;
            W2[i][j] = ipt == '.' ? -1 : ipt - '0';
        }
    }

    fill(d1, d1+N, INF);
    fill(d2, d2+N, INF);
    d1[0] = d2[0] = 0;

    int ans = -1;
    priority_queue<qi, vector<qi>, greater<qi>> pq; pq.emplace(0, 0, 0, 0);
    while (!pq.empty()) {
        auto [w, w1, w2, s] = pq.top(); pq.pop();

        if (w1 > d1[s] && w2 > d2[s]) continue;
        if (s == 1) {
            ans = w;
            break;
        }

        for (int t = 0; t < N; t++) {
            if (W1[s][t] != -1) {
                int nw1 = w1+W1[s][t],
                    nw2 = w2+W2[s][t],
                    nw = nw1*nw2;

                if (nw1 < d1[t] || nw2 < d2[t]) {
                    d1[t] = min(d1[t], nw1);
                    d2[t] = min(d2[t], nw2);
                    pq.emplace(nw, nw1, nw2, t);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
