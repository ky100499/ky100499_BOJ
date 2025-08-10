#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using pdi = pair<double, int>;

const int MAX = 50001, INF = 1e9;

pi A[MAX];
map<int, double> G[MAX];
double D[MAX];

double dist(pi u, pi v)
{
    return sqrt(pow(u.first-v.first, 2) + pow(u.second-v.second, 2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, F; cin >> N >> F; N++;
    A[0] = {0,0};
    for (int i = 1; i < N; i++) cin >> A[i].first >> A[i].second;
    sort(A, A+N);

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (abs(A[i].first - A[j].first) > 2) break;
            if (abs(A[i].second - A[j].second) > 2) continue;

            G[i][j] = G[j][i] = dist(A[i], A[j]);
        }
    }

    int ans = -1;
    fill(D, D+N, INF); D[0] = 0;
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq; pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (A[s].second == F) {
            ans = d + 0.5;
            break;
        }
        if (D[s] < d) continue;

        for (auto [t, w] : G[s]) {
            if (D[t] > d+w) {
                D[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
