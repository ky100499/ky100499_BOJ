#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;

map<string, int> id;
int parent[MAX],
    cnt[MAX];

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(string a, string b)
{
    int _a = find(id[a]), _b = find(id[b]);
    if (_a != _b) {
        parent[_b] = _a;
        cnt[_a] += cnt[_b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int F, n = 0; cin >> F;
        id.clear();
        for (int i = 0; i < 2*F; i++) parent[i] = i;
        fill(cnt, cnt+(2*F), 1);

        while (F--) {
            string a, b; cin >> a >> b;
            if (id.find(a) == id.end()) id[a] = n++;
            if (id.find(b) == id.end()) id[b] = n++;
            merge(a, b);
            cout << cnt[find(id[a])] << '\n';
        }
    }

    return 0;
}
