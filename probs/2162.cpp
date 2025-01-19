#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

const int MAX = 3000;

int parent[MAX],
    cnt[MAX];
pi A[MAX][2];

ll op(pi a, pi b)
{
    return a.first*b.second - a.second*b.first;
}

int ccw(pi a, pi b, pi c)
{
    ll z = op({b.first-a.first, b.second-a.second}, {c.first-b.first, c.second-b.second});
    return z > 0 ? 1 : z < 0 ? -1 : 0;
}

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

bool cross(pi a, pi b, pi c, pi d)
{
    int c1 = ccw(a, b, c) * ccw(a, b, d),
        c2 = ccw(c, d, a) * ccw(c, d, b);

    if (c1 == 0 && c2 == 0)
        return min(a, b) <= max(c, d) && min(c, d) <= max(a, b);

    return c1 <= 0 && c2 <= 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++)
            cin >> A[i][j].first >> A[i][j].second;
        parent[i] = i;
    }
    fill(cnt, cnt+N, 1);

    int ans = N;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (find(i) == find(j)) continue;

            if (cross(A[i][0], A[i][1], A[j][0], A[j][1])) {
                merge(i, j);
                ans--;
            }
        }
    }

    cout << ans << '\n' << *max_element(cnt, cnt+N) << '\n';

    return 0;
}
