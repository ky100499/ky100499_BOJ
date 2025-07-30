#include <bits/stdc++.h>

using namespace std;

const int MAX = 11;

int N, A[MAX], O[4], m = 2e9, M = -2e9;
function<int(int,int)> op[] = {
    [](int a, int b)->int { return a + b; },
    [](int a, int b)->int { return a - b; },
    [](int a, int b)->int { return a * b; },
    [](int a, int b)->int { return a / b; },
};

void bt(int n, int v)
{
    if (n == N) {
        m = min(m, v);
        M = max(M, v);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (O[i]) {
            O[i]--;
            bt(n+1, op[i](v, A[n]));
            O[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> O[i];

    bt(1, A[0]);
    cout << M << '\n' << m << '\n';

    return 0;
}
