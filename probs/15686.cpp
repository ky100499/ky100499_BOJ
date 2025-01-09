#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int INF = 1e9;

int N, M, ans = INF;
vector<pi> H, C;
vector<vector<int>> D;

int dist(pi x, pi y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

void bt(int i, int n, vector<int> cdist)
{
    if (n == M) {
        int s = 0;
        for (int d : cdist) s += d;
        ans = min(ans, s);
        return;
    }

    if (i == C.size()) return;

    bt(i+1, n, cdist);
    for (int j = 0; j < H.size(); j++)
        cdist[j] = min(cdist[j], D[i][j]);
    bt(i+1, n+1, cdist);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    H.reserve(2*N); C.reserve(13);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int ipt; cin >> ipt;
            if (ipt == 1) H.emplace_back(i, j);
            else if (ipt == 2) C.emplace_back(i, j);
        }
    }

    D.resize(C.size());
    for (int i = 0; i < C.size(); i++) {
        D[i].resize(H.size());
        for (int j = 0; j < H.size(); j++) {
            D[i][j] = dist(C[i], H[j]);
        }
    }

    bt(0, 0, vector<int>(H.size(), INF));
    cout << ans << '\n';

    return 0;
}
