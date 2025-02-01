#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

vector<pi> pts, ans;
pi O;

int op(pi a, pi b)
{
    return a.first * b.second - a.second * b.first;
}

int ccw(pi a, pi b, pi c)
{
    int z = op(
        { b.first - a.first, b.second - a.second },
        { c.first - b.first, c.second - b.second }
    );

    return z > 0 ? 1 : z < 0 ? -1 : 0;
}

int dist(pi a, pi b)
{
    return pow(b.first - a.first, 2) + pow(b.second - a.second, 2);
}

bool cmp(pi a, pi b)
{
    int c = ccw(O, a, b);
    if (c == 0) return dist(O, a) < dist(O, b);
    else return c < 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        O = {1e9, -1e9};
        pts.resize(N);
        ans.resize(N);
        for (int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            if (y > O.second || y == O.second && x < O.first)
                O = {x, y};
            pts[i] = {x, y};
        }
        sort(pts.begin(), pts.end(), cmp);

        int s = 0;
        for (int i = 0; i < N; i++) {
            while (s >= 2) {
                if (ccw(ans[s-2], ans[s-1], pts[i]) >= 0) s--;
                else break;
            }
            ans[s++] = pts[i];
        }

        cout << s << '\n';
        for (int i = 0; i < s; i++)
            cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}
