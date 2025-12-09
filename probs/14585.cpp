#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int N, M;
map<int, int> A[301][301];
vector<pi> C;

int solve(int x, int y, int m)
{
    if (m <= 0) return 0;
    if (A[x][y].find(m) != A[x][y].end()) return A[x][y][m];

    int ans = 0;
    for (auto [nx, ny] : C) {
        if (nx < x || ny < y) continue;
        if (x == nx && y == ny) continue;
        ans = max(ans, solve(nx, ny, m-nx-ny+x+y));
    }

    return A[x][y][m] = m+ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M; C.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i].first >> C[i].second;

    cout << solve(0, 0, M)-M << '\n';

    return 0;
}
