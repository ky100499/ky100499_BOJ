#include <bits/stdc++.h>

using namespace std;
using di = pair<double, int>;
using dii = tuple<double, int, int>;

const int MAX = 1e5;

int parent[MAX+1];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; i++) parent[i] = i;
    vector<dii> q1; q1.reserve(M);
    for (int i = 0; i < M; i++) {
        int a, b; double p; cin >> a >> b >> p;
        q1.emplace_back(p, a, b);
    }
    int Q; cin >> Q;
    vector<di> q2; q2.reserve(Q);
    for (int i = 0; i < Q; i++) {
        double p; cin >> p;
        q2.emplace_back(p, i);
    }
    sort(q1.begin(), q1.end(), greater<dii>());
    sort(q2.begin(), q2.end(), greater<di>());

    int cnt = N;
    vector<int> ans(Q);
    int i = 0, j = 0;
    while (i < Q && j < M) {
        auto [p, a, b] = q1[j];
        if (p >= q2[i].first) {
            if (find(a) != find(b)) {
                merge(a, b);
                cnt--;
            }
            j++;
        }
        else {
            ans[q2[i].second] = cnt;
            i++;
        }
    }
    while (i < Q) ans[q2[i++].second] = cnt;

    for (int a : ans) cout << a << '\n';

    return 0;
}
