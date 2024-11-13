#include <bits/stdc++.h>

using namespace std;
using pdd = pair<double, double>;
using pdi = pair<double, int>;

int V[100] = {0,};
pdd C[100];

double dist(pdd p1, pdd p2)
{
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> C[i].first >> C[i].second;

    priority_queue<pdi, vector<pdi>, greater<pdi>> pq; pq.emplace(0, 0);
    double ans = 0;
    while (!pq.empty()) {
        auto [c, s] = pq.top(); pq.pop();

        if (!V[s]) {
            ans += c;
            V[s] = 1;
            for (int i = 0; i < N; i++) {
                if (!V[i]) {
                    pq.emplace(dist(C[s], C[i]), i);
                }
            }
        }
    }

    cout.precision(2);
    cout << fixed << ans << '\n';

    return 0;
}
