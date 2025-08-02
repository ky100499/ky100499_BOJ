#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 101;

int A[MAX][MAX],
    mv[][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
/*
** 0: right, 1: up, 2: left, 3: down
*/

vector<int> D[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    D[0].push_back(0);
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < D[i-1].size(); j++)
            D[i].push_back(D[i-1][j]);
        for (int j = D[i-1].size()-1; j >= 0; j--)
            D[i].push_back((D[i-1][j]+1) % 4);
    }

    int N; cin >> N;
    memset(A, 0, sizeof A);
    while (N--) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        A[y][x] = 1;
        for (int i = 0; i < D[g].size(); i++) {
            x += mv[(D[g][i]+d)%4][1];
            y += mv[(D[g][i]+d)%4][0];
            if (in(x, 0, MAX) && in(y, 0, MAX)) A[y][x] = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            ans += A[i][j] && A[i-1][j] && A[i][j-1] && A[i-1][j-1];
    cout << ans << '\n';

    return 0;
}
