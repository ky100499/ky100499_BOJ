#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int A[100][100], B[100][100];
map<int, int> cnt;
vector<pi> tmp;

void transpose(int &r, int &c)
{
    memcpy(B, A, sizeof A);
    memset(A, 0, sizeof A);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            A[j][i] = B[i][j];
    swap(r, c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int r, c, k; cin >> r >> c >> k;

    int R = 3, C = 3;
    memset(A, 0, sizeof A);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    int T = 0;
    while (T <= 100) {
        if (A[r-1][c-1] == k) break;
        T++;

        int len = 0, t = R < C;

        if (t) transpose(R, C);

        for (int i = 0; i < R; i++) {
            cnt.clear(); tmp.clear();
            for (int j = 0; j < C; j++) cnt[A[i][j]]++;

            for (auto [u, v] : cnt)
                if (u) tmp.emplace_back(v, u);
            sort(tmp.begin(), tmp.end());
            int _len = min(50, (int)tmp.size());
            len = max(len, _len*2);

            for (int j = 0; j < _len; j++) {
                A[i][2*j] = tmp[j].second;
                A[i][2*j+1] = tmp[j].first;
            }
            for (int j = _len*2; j < 100; j++) A[i][j] = 0;
        }
        C = len;

        if (t) transpose(R, C);
    }

    cout << (T > 100 ? -1 : T) << '\n';

    return 0;
}
