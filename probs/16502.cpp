#include <bits/stdc++.h>

using namespace std;

double A[4], tmp[4], P[4][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    memset(A, 0, sizeof A);
    for (int i = 0; i < 4; i++) A[i] = 0.25;
    memset(P, 0, sizeof P);
    while (M--) {
        char u, v; cin >> u >> v;
        cin >> P[u-'A'][v-'A'];
    }

    while (N--) {
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp[i] += P[j][i] * A[j];
        memcpy(A, tmp, sizeof A);
    }

    cout << fixed;
    cout.precision(2);
    for (int i = 0; i < 4; i++) cout << A[i]*100 << '\n';

    return 0;
}
