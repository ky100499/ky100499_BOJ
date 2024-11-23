#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5;

pi parent[MAX+1];

pi find(int a)
{
    if (a == parent[a].first) return parent[a];
    else {
        pi pa = find(parent[a].first);
        return parent[a] = {pa.first, pa.second+parent[a].second};
    }
}

void merge(int a, int b, int w)
{
    pi pa = find(a), pb = find(b);
    if (pa.first != pb.first) parent[pb.first] = {pa.first, pa.second+w-pb.second};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        int N, M; cin >> N >> M; if (!N) break;
        for (int i = 1; i <= N; i++) parent[i] = {i, 0};

        while (M--) {
            char op; int a, b, w; cin >> op >> a >> b;
            if (op == '!') {
                cin >> w;
                merge(a, b, w);
            }
            else {
                pi pa = find(a), pb = find(b);
                if (pa.first == pb.first) cout << pb.second - pa.second << '\n';
                else cout << "UNKNOWN\n";
            }
        }
    }

    return 0;
}
