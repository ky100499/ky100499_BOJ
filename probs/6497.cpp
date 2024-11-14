#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 2e5;

int parent[MAX];
ti edges[MAX];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a != b) parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        int M, N, S = 0; cin >> M >> N;
        if (M == 0) break;

        for (int i = 0; i < M; i++) parent[i] = i;

        for (int i = 0; i < N; i++) {
            int x, y, z; cin >> x >> y >> z;
            edges[i] = {z, x, y};
            S += z;
        }
        sort(edges, edges+N);

        for (int i = 0; i < N; i++) {
            auto [z, x, y] = edges[i];
            if (find(x) != find(y)) {
                merge(x, y);
                S -= z;
            }
        }

        cout << S << '\n';
    }

    return 0;
}
