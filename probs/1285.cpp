#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int A[MAX];

int bit_count(int x)
{
    int ret = 0;
    while (x) {
        ret += x&1;
        x >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(A, 0, sizeof A);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            if (c == 'T') A[i] |= 1<<j;
        }
    }

    int ans = N*N;
    for (int i = 0; i < (1<<N); i++) {
        int s = 0;
        for (int j = 0; j < N; j++)
            s += (N - abs(2*bit_count(A[j]^i) - N)) / 2;
        ans = min(ans, s);
    }

    cout << ans << '\n';

    return 0;
}
