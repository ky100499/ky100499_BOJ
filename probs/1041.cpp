#include <bits/stdc++.h>

using namespace std;

int s2[][6] = {
    {1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1},
}, s3[][6] = {
    {1, 1, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 1, 1},
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    long long N; cin >> N;
    int A[6]; for (int i = 0; i < 6; i++) cin >> A[i];
    long long V[3] = {999,999,999};

    if (N == 1) {
        int s = 0, m = 0;
        for (int a : A) {
            s += a;
            m = max(m, a);
        }
        cout << s - m << '\n';
        return 0;
    }

    for (int i = 0; i < 6; i++) V[0] = min((int)V[0], A[i]);
    for (auto dice : s2) {
        int s = 0;
        for (int i = 0; i < 6; i++) s += dice[i] ? A[i] : 0;
        V[1] = min((int)V[1], s);
    }
    for (auto dice : s3) {
        int s = 0;
        for (int i = 0; i < 6; i++) s += dice[i] ? A[i] : 0;
        V[2] = min((int)V[2], s);
    }

    cout << V[0] * (4 * (N-1) * (N-2) + (N-2) * (N-2)) + V[1] * 4 * (N-2 + N-1) + V[2] * 4 << '\n';

    return 0;
}
